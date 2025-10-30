// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OptionsDataRegistry.generated.h"

/**
 * 
 */
class UListDataObject_Collection;

UCLASS()
class ADVANCEDUI_API UOptionsDataRegistry : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * Gets called by options screen right after object of type UOptionsDataRegistry is created.
	 * @param InOwningLocalPlayer 
	 */
	void InitOptionsDataRegistry(ULocalPlayer* InOwningLocalPlayer);
	
	const TArray<UListDataObject_Collection*>& GetRegisteredOptionsTabCollections() const { return RegisteredOptionsTabCollections; }
private:
	void InitGameplayCollectionTab();
	void InitAudioCollectionTab();
	void InitVideoCollectionTab();
	void InitControlCollectionTab();

	UPROPERTY(Transient)
	TArray<UListDataObject_Collection*> RegisteredOptionsTabCollections;
};
