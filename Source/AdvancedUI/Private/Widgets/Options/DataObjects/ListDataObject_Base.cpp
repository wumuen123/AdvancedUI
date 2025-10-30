// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Options/DataObjects/ListDataObject_Base.h"

void UListDataObject_Base::InitDataObject()
{
	// Before init its children ,first init itself. This is already called in base class interface. 有一点模板方法模式。
	OnDataObjectInitialized();
}

void UListDataObject_Base::OnDataObjectInitialized()
{
}
