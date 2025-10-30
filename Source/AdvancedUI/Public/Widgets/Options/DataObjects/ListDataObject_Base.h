// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ListDataObject_Base.generated.h"

#define LIST_DATA_ACCESSOR(DataType, PropertyName) \
	FORCEINLINE DataType Get##PropertyName() const { return PropertyName; } \
	void Set##PropertyName(DataType In##PropertyName) { PropertyName = In##PropertyName; }

/**
 * 
 */
UCLASS()
class ADVANCEDUI_API UListDataObject_Base : public UObject
{
	GENERATED_BODY()
public:
	// Getters and Setters
	LIST_DATA_ACCESSOR(FName, DataID)
	LIST_DATA_ACCESSOR(FText, DataDisplayName)
	LIST_DATA_ACCESSOR(FText, DescriptionRichText)	
	LIST_DATA_ACCESSOR(FText, DisabledRichText)	
	LIST_DATA_ACCESSOR(TSoftObjectPtr<UTexture2D>, SoftDescriptionImage)
	LIST_DATA_ACCESSOR(UListDataObject_Base*, ParentData)

	/**
	 * Patch Init the data objects. (Manage all)
	 */
	void InitDataObject();
	
	/**
	 * 	Empty in this base class. Child class should implement it. The function should return all the child data that a tab has. 
	 */
	virtual TArray<UListDataObject_Base*> GetAllChildListData() const { return TArray<UListDataObject_Base*>(); };
	
	virtual bool HasChildListData() const { return false; };

protected:
	/**
	 * The child classes should implement it, to handle theirs initialization needed accordingly. (Take care of its own business because it can be children)
	 */
	virtual void OnDataObjectInitialized();

private:
	FName DataID;
	FText DataDisplayName;
	FText DescriptionRichText;
	FText DisabledRichText;
	TSoftObjectPtr<UTexture2D> SoftDescriptionImage;

	UPROPERTY(Transient)
	UListDataObject_Base* ParentData;
};
