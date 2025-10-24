// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AdvancedUIPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDUI_API AAdvancedUIPlayerController : public APlayerController
{
	GENERATED_BODY()
protected: 
	// ~ Begin APlayerController Interface
	virtual void OnPossess(APawn* aPawn) override;
	// ~ End APlayerController Interface
};
