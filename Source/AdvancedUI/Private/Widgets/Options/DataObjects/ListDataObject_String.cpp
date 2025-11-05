// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Options/DataObjects/ListDataObject_String.h"
#include "AdvancedUIDebugHelper.h"
#include "Widgets/Options/OptionsDataInteractionHelper.h"


void UListDataObject_String::AddDynamicOption(const FString& InStringValue, const FText& InDisplayText)
{
	AvailableOptionsStringArray.Add(InStringValue);
	AvailableOptionsTextArray.Add(InDisplayText);
}

void UListDataObject_String::AdvanceToNextOption()
{
	if (!AvailableOptionsStringArray.IsEmpty() && !AvailableOptionsTextArray.IsEmpty())
	{
		const int32 CurrentDisplayIndex = AvailableOptionsStringArray.IndexOfByKey(CurrentStringValue);
		const int32 NextIndexToDisplay = CurrentDisplayIndex + 1;
		
		if (const bool bIsNextIndexValid = AvailableOptionsStringArray.IsValidIndex(NextIndexToDisplay))
		{
			CurrentStringValue = AvailableOptionsStringArray[NextIndexToDisplay];
		}
		else
		{
		// return to the first option string
			CurrentStringValue = AvailableOptionsStringArray[0];
		}

		// 只有能更新到 Game User Settings 中，才算是有效更新，否则，不更新前端显示，不进行广播
		if (DataDynamicSetter)
		{
			DataDynamicSetter->SetValueFromString(CurrentStringValue);

			TrySetDisplayTextFromStringValue(CurrentStringValue);
			NotifyListDataModified(this);
		}
	}
}

void UListDataObject_String::BackToPreviousOption()
{
	if (!AvailableOptionsStringArray.IsEmpty() && !AvailableOptionsTextArray.IsEmpty())
	{
		const int32 CurrentDisplayIndex = AvailableOptionsStringArray.IndexOfByKey(CurrentStringValue);
		const int32 PreviousIndexToDisplay = CurrentDisplayIndex - 1;
		
		if (const bool bIsNextIndexValid = AvailableOptionsStringArray.IsValidIndex(PreviousIndexToDisplay))
		{
			CurrentStringValue = AvailableOptionsStringArray[PreviousIndexToDisplay];
		}
		else
		{
			// return to the first option string
			CurrentStringValue = AvailableOptionsStringArray.Last();
		}

		if (DataDynamicSetter)
		{
			DataDynamicSetter->SetValueFromString(CurrentStringValue);

			TrySetDisplayTextFromStringValue(CurrentStringValue);
			NotifyListDataModified(this);
		}
	}
}

void UListDataObject_String::OnDataObjectInitialized()
{
	Super::OnDataObjectInitialized();
	if (!AvailableOptionsStringArray.IsEmpty())
	{
		CurrentStringValue = AvailableOptionsStringArray[0];
	}

	if (DataDynamicGetter.IsValid())
	{
		if (!DataDynamicGetter->GetValueAsString().IsEmpty())
		{
			CurrentStringValue = DataDynamicGetter->GetValueAsString();
		}
	}


	
	if (!TrySetDisplayTextFromStringValue(CurrentStringValue))
	{
		CurrentDisplayText = FText::FromString(TEXT("Invalid Option"));
	};
	
	/* ToDo: Read from the saved string value to set the current string value */
}

bool UListDataObject_String::TrySetDisplayTextFromStringValue(const FString& InStringValue)
{
	const int32 CurrentFoundIndex = AvailableOptionsStringArray.IndexOfByKey(InStringValue);
	if (AvailableOptionsTextArray.IsValidIndex(CurrentFoundIndex))
	{
		CurrentDisplayText = AvailableOptionsTextArray[CurrentFoundIndex];
		return true;
	}
	return false;
}
