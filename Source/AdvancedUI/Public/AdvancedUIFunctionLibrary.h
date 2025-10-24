// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagContainer.h"
#include "AdvancedUIFunctionLibrary.generated.h"

class UWidget_ActivatableBase;
/**
 * 
 */
UCLASS()
class ADVANCEDUI_API UAdvancedUIFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category = "AdvancedUI Function Library")
	static TSoftClassPtr<UWidget_ActivatableBase> GetAdvancedUISoftWidgetClassByTag(UPARAM(meta = (Categories = "AdvancedUI.Widget")) FGameplayTag InWidgetTag);
};
