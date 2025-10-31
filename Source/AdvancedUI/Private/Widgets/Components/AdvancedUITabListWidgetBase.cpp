// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Components/AdvancedUITabListWidgetBase.h"
#include "Components/DynamicEntryBoxBase.h"
#include "Editor/WidgetCompilerLog.h"
#include "Widgets/Components/AdvancedUICommonButtonBase.h"


void UAdvancedUITabListWidgetBase::RequestRegisterTab(const FName& InTabID, const FText& InTabDisplayName)
{
	RegisterTab(InTabID, TabButtonEntryWidgetClass, nullptr);
	if (UAdvancedUICommonButtonBase* FoundButton = Cast<UAdvancedUICommonButtonBase>(GetTabButtonBaseByID(InTabID)))
	{
		FoundButton->SetButtonText(InTabDisplayName);
	};
}
// 用于编辑器中蓝图编译检查。继承自UWidget, 该方法会在编辑器蓝图编译前一刻调用，会输出相应日志，但不会对编译产生例如阻断等影响。
#if WITH_EDITOR	
void UAdvancedUITabListWidgetBase::ValidateCompiledDefaults(class IWidgetCompilerLog& CompileLog) const
{
	Super::ValidateCompiledDefaults(CompileLog);
	if (!TabButtonEntryWidgetClass)
	{
		CompileLog.Error(FText::FromString(TEXT("No Tab Button classes found ! See AdvancedUITabListWidgetBase.cpp for more information")));
	}
}
#endif