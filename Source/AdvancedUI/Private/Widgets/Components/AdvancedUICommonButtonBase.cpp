// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Components/AdvancedUICommonButtonBase.h"
#include "CommonTextBlock.h"
#include "Subsystems/AdvancedUISubsystem.h"

void UAdvancedUICommonButtonBase::SetButtonText(FText InText)
{
	if (CommonTextBlock_ButtonText && !InText.IsEmpty()) {
		CommonTextBlock_ButtonText->SetText(bUserUpperCaseForButtonText? InText.ToUpper() : InText);
	}
}

void UAdvancedUICommonButtonBase::NativePreConstruct()
{
	Super::NativePreConstruct();
	SetButtonText(ButtonDisplayText);
}

void UAdvancedUICommonButtonBase::NativeOnCurrentTextStyleChanged()
{
	Super::NativeOnCurrentTextStyleChanged();
	if (CommonTextBlock_ButtonText && GetCurrentTextStyleClass()) {
		CommonTextBlock_ButtonText->SetStyle(GetCurrentTextStyleClass());
	}
}

void UAdvancedUICommonButtonBase::NativeOnHovered()
{
	Super::NativeOnHovered();
	if (!ButtonDiscriptionText.IsEmpty()) {
		UAdvancedUISubsystem::Get(this)->OnButtonDescriptionTextUpdated.Broadcast(this, ButtonDiscriptionText);
	}
	else {
		UAdvancedUISubsystem::Get(this)->OnButtonDescriptionTextUpdated.Broadcast(this, FText::FromString(TEXT("No Description")));
	}	
}

void UAdvancedUICommonButtonBase::NativeOnUnhovered()
{
	Super::NativeOnUnhovered();
	UAdvancedUISubsystem::Get(this)->OnButtonDescriptionTextUpdated.Broadcast(this, FText::GetEmpty());
}
