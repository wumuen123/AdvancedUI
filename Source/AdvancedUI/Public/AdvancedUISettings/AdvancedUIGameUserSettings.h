// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "AdvancedUIGameUserSettings.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDUI_API UAdvancedUIGameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()
public:
	static UAdvancedUIGameUserSettings *Get();

	// ***** Gameplay Collection Tab ***** //
	UFUNCTION()
	FString GetCurrentGameDifficulty() const { return CurrentGameDifficulty; }

	UFUNCTION()
	void SetCurrentGameDifficulty(const FString InNewDifficulty) { CurrentGameDifficulty = InNewDifficulty; };
	// ***** Gameplay Collection Tab ***** //

	
private:
	UPROPERTY(Config)
	FString CurrentGameDifficulty;
};
