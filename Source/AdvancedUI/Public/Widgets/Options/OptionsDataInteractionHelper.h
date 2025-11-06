// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PropertyPathHelpers.h"
class UAdvancedUIGameUserSettings;
/**
 * 兼具 Set 和 Get 的功能。也就是说, 如果作为 Getter, 则SetValueFromString是无效方法; 如果作为 Setter, 则 GetValueAsString 是无效方法. 因为 在初始化时, 根据要将这个类的实例要作为 Getter 还是 Setter, 传递的 InSetterOrGetterFuncPath 对应了 UAdvancedUIGameUserSettings 中相应游戏设置选项的 Getter 或 Setter. 这就导致了如果初始化传递了UAdvancedUIGameUserSettings 中相应游戏设置选项的 Getter 的话(说明向编码者想将这个类的实例作为Getter), 却使用SetValueFromString, 而成员变量CachedDynamicFunctionPath是游戏设置选项的 Getter, 这就会导致与SetValueFromString中的PropertyPathHelpers::SetPropertyValueFromString函数发生冲突, 是无效操作.
 *
 *
 * 初始化该类的实例时, 一般都会在实例变量名中写明是Getter还是Setter, 请根据字面量使用对应的GetValueAsString或是SetValueFromString方法。
 */
class ADVANCEDUI_API FOptionsDataInteractionHelper
{
public:
	// Setter or Getter Func 来自 Game User Settings, 为某个游戏设置的 Getter 或者 Setter
	FOptionsDataInteractionHelper(const FString& InSetterOrGetterFuncPath);

	FString GetValueAsString() const;
	void SetValueFromString(const FString& InStringValue);
private:
	FCachedPropertyPath CachedDynamicFunctionPath;

	// 用一下这个智能指针
	TWeakObjectPtr<UAdvancedUIGameUserSettings> CachedWeakGameUserSettings;
};
