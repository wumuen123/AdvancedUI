// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AdvancedUITypes/AdvancedUIEnumTypes.h"
#include "Blueprint/IUserObjectListEntry.h"

#include "Widget_ListEntry_Base.generated.h"

class UCommonTextBlock;
class UListDataObject_Base;
/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta=(DisableNaiveTick))
class ADVANCEDUI_API UWidget_ListEntry_Base : public UCommonUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName="On Lis tEntry Widget Hovered"))
	void BP_OnListEntryWidgetHovered(bool bWasHovered, bool bIsEntryWidgetStillSelected);
	void NativeOnListEntryWidgetHovered(bool bWasHovered);
protected:
	//~ Begin IUserObjectListEntry Interface
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	//~ End IUserObjectListEntry Interface

	// The child class should implement it
	virtual void OnOwningListDataObjectSet(UListDataObject_Base* InOwningListDataObject);

	// The child class should implement it
	virtual void OnOwningListDataObjectModified(UListDataObject_Base* OwningModifiedData, EOptionsListDataModifyReason ModifiedReason);
	
private:
	// ***** Bound Widgets ***** //
	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional, AllowPrivateAccess = "true"))
	UCommonTextBlock* CommonText_SettingDisplayName;
	// ***** Bound Widgets ***** //
};
