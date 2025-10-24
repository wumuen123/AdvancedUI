// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Widget_ActivatableBase.generated.h"

class AAdvancedUIPlayerController;
/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta = (DisableNaiveTick))
class ADVANCEDUI_API UWidget_ActivatableBase : public UCommonActivatableWidget
{
	GENERATED_BODY()
protected:
	UFUNCTION(BlueprintPure)
	AAdvancedUIPlayerController* GetOwningAdvancedUIPlayerController();
private:
	TWeakObjectPtr<AAdvancedUIPlayerController> CachedOwningAdvancedUIPC;

};
