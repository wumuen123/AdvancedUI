// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Components/AdvancedUICommonListView.h"
#include "Editor/WidgetCompilerLog.h"
#include "Widgets/Options/DataAsset_DataListEntryMapping.h"
#include "Widgets/Options/ListEntries/Widget_ListEntryBase.h"
#include "Widgets/Options/DataObjects/ListDataObject_Base.h"


UUserWidget& UAdvancedUICommonListView::OnGenerateEntryWidgetInternal(UObject* Item,
	TSubclassOf<UUserWidget> DesiredEntryClass, const TSharedRef<STableViewBase>& OwnerTable)
{
	if (IsDesignTime())
	{
		return Super::OnGenerateEntryWidgetInternal(Item, DesiredEntryClass, OwnerTable);
	}

	TSubclassOf<UWidget_ListEntryBase> FoundWidgetClass = DataListEntryMapping->FindEntryWidgetClassByDataObject(CastChecked<UListDataObject_Base>(Item));
	return GenerateTypedEntry<UWidget_ListEntryBase>(FoundWidgetClass, OwnerTable);
}

#if WITH_EDITOR	
void UAdvancedUICommonListView::ValidateCompiledDefaults(class IWidgetCompilerLog& CompileLog) const
{
	Super::ValidateCompiledDefaults(CompileLog);
	if (!DataListEntryMapping)
	{
		CompileLog.Error(FText::FromString(TEXT("Missing required field 'DataListEntryMapping', see AdvancedUICommonListView.cpp for more information")));
	}
}
#endif