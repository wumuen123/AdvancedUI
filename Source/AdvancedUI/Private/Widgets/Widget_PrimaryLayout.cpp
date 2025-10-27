// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Widget_PrimaryLayout.h"
#include "AdvancedUIDebugHelper.h"

UCommonActivatableWidgetContainerBase* UWidget_PrimaryLayout::FindWidgetStackByTag(const FGameplayTag& InTag) const
{
	//如果条件为false，则会立即崩溃
	checkf(RegisteredWidgetStackMap.Contains(InTag), TEXT("Can' t find the widget stack by the tag %s"), *InTag.ToString())
	return RegisteredWidgetStackMap.FindRef(InTag);
}

void UWidget_PrimaryLayout::RegisterWidgetStack(UPARAM(meta = (Categories = "AdvancedUI.WidgetStack")) FGameplayTag InStackTag, UCommonActivatableWidgetContainerBase* InStack)
{
	if (!IsDesignTime() && !RegisteredWidgetStackMap.Contains(InStackTag)) { //判断是否在runtime, 以及stack中是否已经存在即将要推送的InStackTag
		RegisteredWidgetStackMap.Add(InStackTag, InStack);
	}
}
