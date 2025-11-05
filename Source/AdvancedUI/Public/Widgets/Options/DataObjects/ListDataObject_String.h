// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Options/DataObjects/ListDataObject_Value.h"
#include "ListDataObject_String.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDUI_API UListDataObject_String : public UListDataObject_Value
{
	GENERATED_BODY()
public:
	void AddDynamicOption(const FString& InStringValue, const FText& InDisplayText);

	void AdvanceToNextOption();
	void BackToPreviousOption();
	
protected:
	// ~Begin UListDataObject_Base Interface
	virtual void OnDataObjectInitialized() override;
	// ~End UListDataObject_Base Interface

	bool TrySetDisplayTextFromStringValue(const FString& InStringValue);
	
	FString CurrentStringValue;
	FText CurrentDisplayText;
	
	TArray<FString> AvailableOptionsStringArray;
	TArray<FText> AvailableOptionsTextArray;

	//Getters and Setters
public:
	FORCEINLINE const TArray<FText>& GetAvailableOptionsTextArray() { return AvailableOptionsTextArray; }
	FORCEINLINE FText GetCurrentDisplayText() { return CurrentDisplayText; }
};
