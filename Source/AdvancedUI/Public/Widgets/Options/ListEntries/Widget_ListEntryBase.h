// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"

#include "Widget_ListEntryBase.generated.h"

class UCommonTextBlock;
/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta=(DisableNaiveTick))
class ADVANCEDUI_API UWidget_ListEntryBase : public UCommonUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	//~ Begin IUserObjectListEntry Interface
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	//~ End IUserObjectListEntry Interface
private:
	// ***** Bound Widgets ***** //
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional, AllowPrivateAccess = "true"))
	UCommonTextBlock* CommonText_SettingDisplayName;
	// ***** Bound Widgets ***** //
};
