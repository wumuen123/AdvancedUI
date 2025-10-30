// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Widget_ActivatableBase.h"
#include "Widget_OptionsScreen.generated.h"

class UAdvancedUITabListWidgetBase;
class UOptionsDataRegistry;

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
	// ~ Begin UCommonActivatableWidget Interface;
private:
	UOptionsDataRegistry* GetOrCreateDataRegistry();
	
	void OnResetBoundActionTriggered();
	void OnBackBoundActionTriggered();

	/**
	 * Handle the data creation in options screen. Direct access to this variable is forbidden. Due to some "Common UI nature "
	 */
	UPROPERTY(Transient)
	UOptionsDataRegistry* CreatedOwningDataRegistry;
	
	UPROPERTY(EditDefaultsOnly, Category = "AdvancedUI Options Screen", meta = (RowType = "/Script/CommonUI.CommonInputActionDataBase"))
	FDataTableRowHandle ResetAction;
	
	FUIActionBindingHandle ResetActionHandle;

	// ***** Bound Widgets ***** //
	UPROPERTY(meta=(BindWidget))
	UAdvancedUITabListWidgetBase* TabListWidget_OptionsTabs;
	// ***** Bound Widgets ***** //
	
};
