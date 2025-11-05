// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedUISettings/AdvancedUIGameUserSettings.h"

UAdvancedUIGameUserSettings* UAdvancedUIGameUserSettings::Get()
{
	if (GEngine)
	{
		UAdvancedUIGameUserSettings* GameUserSettings = Cast<UAdvancedUIGameUserSettings>(GEngine->GetGameUserSettings());
		return GameUserSettings;
	}
	return nullptr;
}
