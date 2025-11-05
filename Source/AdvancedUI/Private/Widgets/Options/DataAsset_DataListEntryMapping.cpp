// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Options/DataAsset_DataListEntryMapping.h"
#include "Widgets/Options/DataObjects/ListDataObject_Base.h"


TSubclassOf<UWidget_ListEntry_Base> UDataAsset_DataListEntryMapping::FindEntryWidgetClassByDataObject(
	const UListDataObject_Base* InDataObject) const
{
	check(InDataObject);
	// Retrieve parent class
	for (UClass* DataObjectClass = InDataObject->GetClass(); DataObjectClass; DataObjectClass = DataObjectClass->GetSuperClass())
	{
		TSubclassOf<UListDataObject_Base> ConvertedDataObjectClass = TSubclassOf<UListDataObject_Base>(DataObjectClass);
		if (ConvertedDataObjectClass && DataObjectListEntryMap.Contains(ConvertedDataObjectClass))
		{
			//return DataObjectListEntryMap[ConvertedDataObjectClass];
			return DataObjectListEntryMap.FindRef(ConvertedDataObjectClass);
		}
	}

	return TSubclassOf<UWidget_ListEntry_Base>();
}
