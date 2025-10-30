// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Options/DataObjects/ListDataObject_Base.h"
#include "ListDataObject_Collection.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDUI_API UListDataObject_Collection : public UListDataObject_Base
{
	GENERATED_BODY()

public:
	void AddChildListData(UListDataObject_Base* InChildListData);


	
	//~ Begin UListDataObject_Base Interface
	virtual TArray<UListDataObject_Base*> GetAllChildListData() const override;
	virtual bool HasChildListData() const override;
	//~ End UListDataObject_Base Interface
	
private:
	UPROPERTY(Transient)
	TArray<UListDataObject_Base*> ChildListArray;
};
