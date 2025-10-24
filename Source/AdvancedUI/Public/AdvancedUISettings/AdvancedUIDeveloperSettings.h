// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "GameplayTagContainer.h"
#include "AdvancedUIDeveloperSettings.generated.h"

class UWidget_ActivatableBase;
/**
 * 
 */
UCLASS(Config = Game, defaultconfig, meta = (DisplayName = "Advanced UI Settings"))
class ADVANCEDUI_API UAdvancedUIDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UPROPERTY(Config, EditAnywhere, Category = "Widget Reference", meta = (ForceInlineRow, Categories = "AdvancedUI.Widget"))
	TMap<FGameplayTag, TSoftClassPtr<UWidget_ActivatableBase>> AdvancedUIWidgetMap;
};
