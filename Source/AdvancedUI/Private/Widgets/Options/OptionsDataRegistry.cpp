// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Options/OptionsDataRegistry.h"
#include "Widgets/Options/DataObjects/ListDataObject_Collection.h"

#define INIT_COLLECTION_TAB(CollectionTabName) \
void UOptionsDataRegistry::Init##CollectionTabName##CollectionTab() \
{ \
	UListDataObject_Collection* ##CollectionTabName##TabCollection = NewObject<UListDataObject_Collection>(); \
	##CollectionTabName##TabCollection->SetDataID(FName(#CollectionTabName "TabCollection")); \
	##CollectionTabName##TabCollection->SetDataDisplayName(FText::FromString(TEXT(#CollectionTabName))); \
	RegisteredOptionsTabCollections.Add(##CollectionTabName##TabCollection); \
} \

void UOptionsDataRegistry::InitOptionsDataRegistry(ULocalPlayer* InOwningLocalPlayer)
{
	InitGameplayCollectionTab();
	InitAudioCollectionTab();
	InitVideoCollectionTab();
	InitControlCollectionTab();
}

INIT_COLLECTION_TAB(Gameplay)
INIT_COLLECTION_TAB(Audio)
INIT_COLLECTION_TAB(Video)
INIT_COLLECTION_TAB(Control)

