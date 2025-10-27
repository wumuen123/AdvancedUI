// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/AdvancedUISubsystem.h"
#include "Engine/AssetManager.h"
#include "Widgets/Widget_PrimaryLayout.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "Widgets/Widget_ActivatableBase.h"
#include "Widgets/Widget_ConfirmScreen.h"
#include "AdvancedUIGameplayTags.h"
#include "AdvancedUIDebugHelper.h"
#include "AdvancedUIFunctionLibrary.h"

// 访问我们的AdvancedUI子系统
UAdvancedUISubsystem* UAdvancedUISubsystem::Get(const UObject* WorldContextObject) {
	if (GEngine) {
		UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert);
		return UGameInstance::GetSubsystem<UAdvancedUISubsystem>(World->GetGameInstance());
	}
	return nullptr;
}

// 在子系统将要被实例化时自动调用，判断是否应该继续实例化该子系统
bool UAdvancedUISubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	if (!CastChecked<UGameInstance>(Outer)->IsDedicatedServerInstance()) {
		TArray<UClass*> FoundClasses;
		GetDerivedClasses(GetClass(), FoundClasses);

		return FoundClasses.IsEmpty();
	}
	return false;
}

//将创建的Primary_LayoutWidget注册到子系统中
void UAdvancedUISubsystem::RegisterCreatedPrimaryLayoutWidget(UWidget_PrimaryLayout* InCreatedWidget)
{
	check(InCreatedWidget)
		CreatedPrimaryLayout = InCreatedWidget;
}

void UAdvancedUISubsystem::PushSoftWidgetToStackAsync(const FGameplayTag& InWidgetStackTag, TSoftClassPtr<UWidget_ActivatableBase> InSoftWidgetClass, TFunction<void(EAsyncPushWidgetState, UWidget_ActivatableBase*)> AsyncPushStateCallback)
{
	check(!InSoftWidgetClass.IsNull())
	UAssetManager::Get().GetStreamableManager().RequestAsyncLoad(
		InSoftWidgetClass.ToSoftObjectPath(),
		FStreamableDelegate::CreateLambda(
			[InSoftWidgetClass, this, InWidgetStackTag, AsyncPushStateCallback]() {
				UClass* LoadedWidgetClass = InSoftWidgetClass.Get();
				check(LoadedWidgetClass && CreatedPrimaryLayout)
				UCommonActivatableWidgetContainerBase* FoundWidgetStack = CreatedPrimaryLayout->FindWidgetStackByTag(InWidgetStackTag);
				UWidget_ActivatableBase* CreatedWidget = FoundWidgetStack->AddWidget<UWidget_ActivatableBase>(
					LoadedWidgetClass,
					[AsyncPushStateCallback](UWidget_ActivatableBase& CreatedWidgetInstance) {
						AsyncPushStateCallback(EAsyncPushWidgetState::OnCreatedBeforePush, &CreatedWidgetInstance);
					}
				);
				AsyncPushStateCallback(EAsyncPushWidgetState::AfterPush, CreatedWidget);
			}
		)
	);
}

void UAdvancedUISubsystem::PushConfirmScreenToModalStackAynsc(EConfirmScreenType InScreenType, const FText& InScreenTitle, const FText& InScreenMessage, TFunction<void(EConfirmScreenButtonType)> ButtonClickedCallback)
{
	UConfirmScreenInfoObject* CreatedInfoObject = nullptr;
	switch (InScreenType)
	{
	case EConfirmScreenType::Ok:
		CreatedInfoObject = UConfirmScreenInfoObject::CreateOKScreen(InScreenTitle, InScreenMessage);
		break;
	case EConfirmScreenType::YesNo:
		CreatedInfoObject = UConfirmScreenInfoObject::CreateYesNoScreen(InScreenTitle, InScreenMessage);
		break;
	case EConfirmScreenType::OkCancel:
		CreatedInfoObject = UConfirmScreenInfoObject::CreateOKCancelScreen(InScreenTitle, InScreenMessage);
		break;
	case EConfirmScreenType::Unknown:
		break;
	default:
		break;
	}

	check(CreatedInfoObject);

	PushSoftWidgetToStackAsync(
		AdvancedUIGameplayTags::AdvancedUI_WidgetStack_Modal,
		UAdvancedUIFunctionLibrary::GetAdvancedUISoftWidgetClassByTag(AdvancedUIGameplayTags::AdvancedUI_Widet_ConfirmScreen),
		[CreatedInfoObject, ButtonClickedCallback](EAsyncPushWidgetState InPushState, UWidget_ActivatableBase* PushedWidget) {
			if (InPushState == EAsyncPushWidgetState::OnCreatedBeforePush) {
				UWidget_ConfirmScreen* CreatedConfirmScreen = CastChecked<UWidget_ConfirmScreen>(PushedWidget);
				CreatedConfirmScreen->InitConfirmScreen(CreatedInfoObject, ButtonClickedCallback);
			}
		}
	);
}
// lambda函数可以暂时当作箭头函数理解
// 别说“调用lambda函数”了，而是“调用这个函数变量”
//函数类型变量，当然能被传递和调用
