// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Options/DataObjects/ListDataObject_Collection.h"

void UListDataObject_Collection::AddChildListData(UListDataObject_Base* InChildListData)
{
	// 1. Notify the InChildListData to init itself.
	InChildListData->InitDataObject();
	// 2. Set the child list data 's parent to this.
	InChildListData->SetParentData(this);
	
	ChildListArray.Add(InChildListData);
}

TArray<UListDataObject_Base*> UListDataObject_Collection::GetAllChildListData() const
{
	return ChildListArray;
}

bool UListDataObject_Collection::HasChildListData() const
{
	return !ChildListArray.IsEmpty();
}
