// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedUIFunctionLibrary.h"
#include "AdvancedUISettings/AdvancedUIDeveloperSettings.h"

TSoftClassPtr<UWidget_ActivatableBase> UAdvancedUIFunctionLibrary::GetAdvancedUISoftWidgetClassByTag(UPARAM(meta = (Categories = "AdvancedUI.Widget")) FGameplayTag InWidgetTag)
{
	const UAdvancedUIDeveloperSettings* AdvancedUIDeveloperSettings = GetDefault<UAdvancedUIDeveloperSettings>();
	checkf(AdvancedUIDeveloperSettings->AdvancedUIWidgetMap.Contains(InWidgetTag), TEXT("You just request a soft widget calss by a tag that does not exist, see AdvancedUIFunctionLibrary.cpp for more information"));
	return AdvancedUIDeveloperSettings->AdvancedUIWidgetMap.FindRef(InWidgetTag);

}
