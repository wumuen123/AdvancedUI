// Fill out your copyright notice in the Description page of Project Settings.
#include "Widgets/Options/ListEntries/Widget_ListEntry_Base.h"
#include "CommonTextBlock.h"
#include "Components/ListView.h"
#include "Widgets/Options/DataObjects/ListDataObject_Base.h"
#include "Components/ListViewBase.h"

void UWidget_ListEntry_Base::NativeOnListEntryWidgetHoveredChanged(bool bWasHovered)
{
	BP_OnListEntryWidgetHoveredChanged(bWasHovered, IsListItemSelected());
}

void UWidget_ListEntry_Base::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	SetVisibility(ESlateVisibility::Visible);
	OnOwningListDataObjectSet(CastChecked<UListDataObject_Base>(ListItemObject));
	
}

void UWidget_ListEntry_Base::OnOwningListDataObjectSet(UListDataObject_Base* InOwningListDataObject)
{
	if (CommonText_SettingDisplayName)
	{
		CommonText_SettingDisplayName->SetText(InOwningListDataObject->GetDataDisplayName());
	}
	
	// 只有在没有绑定的时候绑定，防止绑定一个方法多次
	// this 表示指向自己的一个指针
	if (!InOwningListDataObject->OnListDataModified.IsBoundToObject(this))
	{
		InOwningListDataObject->OnListDataModified.AddUObject(this, &ThisClass::OnOwningListDataObjectModified);
	}
}

void UWidget_ListEntry_Base::OnOwningListDataObjectModified(UListDataObject_Base* OwningModifiedData,
	EOptionsListDataModifyReason ModifiedReason)
{
}

void UWidget_ListEntry_Base::SelectThisEntryWidget()
{
	if (UListView* CastedOwningListView = Cast<UListView>(GetOwningListView()))
	{
		CastedOwningListView->SetSelectedItem(GetListItem());
	}
}
