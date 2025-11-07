// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AdvancedUITypes/AdvancedUIEnumTypes.h"
#include "Widgets/Widget_ActivatableBase.h"
#include "Widget_OptionsScreen.generated.h"

class UAdvancedUICommonListView;
class UAdvancedUITabListWidgetBase;
class UOptionsDataRegistry;
class UWidget_OptionsDetailsView;
class UListDataObject_Base;

/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta=(DisableNaiveTick))
class ADVANCEDUI_API UWidget_OptionsScreen : public UWidget_ActivatableBase
{
	GENERATED_BODY()
protected:
	// ~ Begin UUserWidget Interface;
	virtual void NativeOnInitialized() override;
	// ~ End UUserWidget Interface;

	// ~ Begin UCommonActivatableWidget Interface;
	virtual void NativeOnActivated() override;
	virtual void NativeOnDeactivated() override;
	// ~ Begin UCommonActivatableWidget Interface;
private:
	UOptionsDataRegistry* GetOrCreateDataRegistry();
	
	void OnResetBoundActionTriggered();
	void OnBackBoundActionTriggered();

	void OnListViewItemHoveredChanged(UObject* InHoveredItem, bool bWasHovered); // 适用于 hovered, unhovered 两种情况
	void OnListViewItemSelectedChanged(UObject* InSelectedItem); // 

	UFUNCTION()
	void OnOptionsTabSelected(FName TabID);

	FString TryGetEntryWidgetClassName(UObject* InOwningListItem) const;

	void OnListViewListDataModified(UListDataObject_Base* ModifiedData, EOptionsListDataModifyReason ModifyReason);

	/**
	 * Handle the data creation in options screen. Direct access to this variable is forbidden. Due to some "Common UI nature "
	 */
	UPROPERTY(Transient)
	UOptionsDataRegistry* CreatedOwningDataRegistry;
	
	UPROPERTY(EditDefaultsOnly, Category = "AdvancedUI Options Screen", meta = (RowType = "/Script/CommonUI.CommonInputActionDataBase"))
	FDataTableRowHandle ResetAction;
	
	FUIActionBindingHandle ResetActionHandle;

	UPROPERTY(Transient)
	TArray<UListDataObject_Base*> ResettableDataArray;

	bool bIsResettingData = false;

	// ***** Bound Widgets ***** //
	UPROPERTY(meta=(BindWidget))
	UAdvancedUITabListWidgetBase* TabListWidget_OptionsTabs;

	UPROPERTY(meta=(BindWidget))
	UAdvancedUICommonListView* CommonListView_OptionsList;

	UPROPERTY(meta=(BindWidget))
	UWidget_OptionsDetailsView* DetailsView_ListEntryInfo;
	// ***** Bound Widgets ***** //
	
};
