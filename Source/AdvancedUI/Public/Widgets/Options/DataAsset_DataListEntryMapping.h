// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataObjects/ListDataObject_Base.h"
#include "Engine/DataAsset.h"
#include "ListEntries/Widget_ListEntryBase.h"
#include "DataAsset_DataListEntryMapping.generated.h"

class UListDataObject_Base;
class UWidget_ListEntryBase;
/**
 * 
 */
UCLASS()
class ADVANCEDUI_API UDataAsset_DataListEntryMapping : public UDataAsset
{
	GENERATED_BODY()
public:
	TSubclassOf<UWidget_ListEntryBase> FindEntryWidgetClassByDataObject(const UListDataObject_Base* InDataObject) const;
	
private:
	UPROPERTY(EditDefaultsOnly)
	TMap<TSubclassOf<UListDataObject_Base>, TSubclassOf<UWidget_ListEntryBase>> DataObjectListEntryMap;
	
};
