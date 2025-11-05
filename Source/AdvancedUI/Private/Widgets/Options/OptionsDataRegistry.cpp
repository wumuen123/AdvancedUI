// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Options/OptionsDataRegistry.h"
#include "Widgets/Options/DataObjects/ListDataObject_Collection.h"
#include "Widgets/Options/DataObjects/ListDataObject_String.h"


#define INIT_COLLECTION_TAB(CollectionTabName) \
	void UOptionsDataRegistry::Init##CollectionTabName##CollectionTab() \
	{ \
	UListDataObject_Collection* ##CollectionTabName##TabCollection = NewObject<UListDataObject_Collection>(); \
	##CollectionTabName##TabCollection->SetDataID(FName(#CollectionTabName "TabCollection")); \
	##CollectionTabName##TabCollection->SetDataDisplayName(FText::FromString(TEXT(#CollectionTabName))); \
	\
	/* 分别为Gameplay, Audio, Video, Control注入对应的逻辑 */ \
	ADD_##CollectionTabName##_TAB_ITEMS(##CollectionTabName##TabCollection); \
	\
	RegisteredOptionsTabCollections.Add(##CollectionTabName##TabCollection); \
	}\


// 为 Gameplay Tab 定义特定逻辑
#define ADD_Gameplay_TAB_ITEMS(TabCollection) \
	UListDataObject_String* GameDifficulty = NewObject<UListDataObject_String>(); \
	GameDifficulty->SetDataID(FName("GameDifficulty")); \
	GameDifficulty->SetDataDisplayName(FText::FromString(TEXT("Difficulty"))); \
	GameDifficulty->AddDynamicOption(TEXT("Easy"), FText::FromString(TEXT("Easy"))); \
	GameDifficulty->AddDynamicOption(TEXT("Normal"), FText::FromString(TEXT("Normal"))); \
	GameDifficulty->AddDynamicOption(TEXT("Hard"), FText::FromString(TEXT("Hard"))); \
	GameDifficulty->AddDynamicOption(TEXT("Very Hard"), FText::FromString(TEXT("Very Hard"))); \
	\
	TabCollection->AddChildListData(GameDifficulty); \


// 为 Audio Tab 定义特定逻辑
#define ADD_Audio_TAB_ITEMS(tabCollection) \
	int32 a = 8;\

#define ADD_Video_TAB_ITEMS(tabCollection) \


#define ADD_Control_TAB_ITEMS(tabCollection) \

void UOptionsDataRegistry::InitOptionsDataRegistry(ULocalPlayer* InOwningLocalPlayer)
{
	InitGameplayCollectionTab();
	InitAudioCollectionTab();
	InitVideoCollectionTab();
	InitControlCollectionTab();
}

TArray<UListDataObject_Base*> UOptionsDataRegistry::GetListSourceItemsBySelectedTabID(
	const FName& InSelectedTabID) const
{
	if (!RegisteredOptionsTabCollections.IsEmpty())
	{
		UListDataObject_Collection* const* FoundTabCollectionPtr = RegisteredOptionsTabCollections.FindByPredicate(
			[InSelectedTabID](const UListDataObject_Collection* AvailableTabCollection)->bool
			{
				return AvailableTabCollection->GetDataID() == InSelectedTabID;
			}
		);

		checkf(FoundTabCollectionPtr, TEXT("TabCollection is not found somehow, see OptionsDataRegistry.cpp for more information"));

		const UListDataObject_Collection* FoundTabCollection = *FoundTabCollectionPtr;
		return FoundTabCollection->GetAllChildListData();
	} else
	{
		return TArray<UListDataObject_Base*>();
	}
}

INIT_COLLECTION_TAB(Gameplay)
INIT_COLLECTION_TAB(Audio)
INIT_COLLECTION_TAB(Video)
INIT_COLLECTION_TAB(Control)

