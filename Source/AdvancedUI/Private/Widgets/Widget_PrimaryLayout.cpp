// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Widget_PrimaryLayout.h"
#include "AdvancedUIDebugHelper.h"

UCommonActivatableWidgetContainerBase* UWidget_PrimaryLayout::FindWidgetStackByTag(const FGameplayTag& InTag) const
{
	//�������Ϊfalse�������������
	checkf(RegisteredWidgetStackMap.Contains(InTag), TEXT("Can' t find the widget stack by the tag %s"), *InTag.ToString())
	return RegisteredWidgetStackMap.FindRef(InTag);
}

void UWidget_PrimaryLayout::RegisterWidgetStack(UPARAM(meta = (Categories = "AdvancedUI.WidgetStack")) FGameplayTag InStackTag, UCommonActivatableWidgetContainerBase* InStack)
{
	if (!IsDesignTime() && !RegisteredWidgetStackMap.Contains(InStackTag)) { //�ж��Ƿ���runtime, �Լ�stack���Ƿ��Ѿ����ڼ���Ҫ���͵�InStackTag
		RegisteredWidgetStackMap.Add(InStackTag, InStack);
	}
}
