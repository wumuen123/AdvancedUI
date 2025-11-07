 // Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Options/ListEntries/Widget_ListEntry_String.h"

#include "Widgets/Components/AdvancedUICommonButtonBase.h"
#include "Widgets/Components/AdvancedUICommonRotator.h"
#include "Widgets/Options/DataObjects/ListDataObject_String.h"
#include "AdvancedUIDebugHelper.h"

void UWidget_ListEntry_String::NativeOnInitialized()
{
	Super::NativeOnInitialized();
 	CommonButton_PreviousOption->OnClicked().AddUObject(this, &ThisClass::OnPreviousOptionButtonClicked);
	CommonButton_NextOption->OnClicked().AddUObject(this, &ThisClass::OnNextOptionButtonClicked);

	CommonRotator_AvailableOptions->OnClicked().AddLambda(
		[this]()
		{
			SelectThisEntryWidget();
		}
	);
}

void UWidget_ListEntry_String::OnOwningListDataObjectSet(UListDataObject_Base* InOwningListDataObject)
{
	Super::OnOwningListDataObjectSet(InOwningListDataObject);
	CachedOwningStringDataObject = Cast<UListDataObject_String>(InOwningListDataObject);
	if (CachedOwningStringDataObject)
	{
		CommonRotator_AvailableOptions->PopulateTextLabels(CachedOwningStringDataObject->GetAvailableOptionsTextArray());
		CommonRotator_AvailableOptions->SetSelectedOptionByText(CachedOwningStringDataObject->GetCurrentDisplayText());
	}
}

 void UWidget_ListEntry_String::OnOwningListDataObjectModified(UListDataObject_Base* OwningModifiedData,
	 EOptionsListDataModifyReason ModifiedReason)
 {
	 // Super::OnOwningListDataObjectModified(OwningModifiedData, ModifiedReason);
	if (CachedOwningStringDataObject)
	{
		CommonRotator_AvailableOptions->SetSelectedOptionByText(CachedOwningStringDataObject->GetCurrentDisplayText());
	}
 }

 void UWidget_ListEntry_String::OnPreviousOptionButtonClicked()
 {
	if (CachedOwningStringDataObject)
	{
		CachedOwningStringDataObject->BackToPreviousOption();
	}
	SelectThisEntryWidget();
 }

 void UWidget_ListEntry_String::OnNextOptionButtonClicked()
 {
	if (CachedOwningStringDataObject)
	{
		CachedOwningStringDataObject->AdvanceToNextOption();
	}
	SelectThisEntryWidget();
 }
