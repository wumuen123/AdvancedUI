// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PropertyPathHelpers.h"
class UAdvancedUIGameUserSettings;
/**
 * 
 */
class ADVANCEDUI_API FOptionsDataInteractionHelper
{
public:
	FOptionsDataInteractionHelper(const FString& InSetterOrGetterFuncPath);

	FString GetValueAsString() const;
	void SetValueFromString(const FString& InStringValue);
private:
	FCachedPropertyPath CachedDynamicFunctionPath;

	// 因为不是从ue继承的任何类，所以用一下这个智能执政
	TWeakObjectPtr<UAdvancedUIGameUserSettings> CachedWeakGameUserSettings;
};
