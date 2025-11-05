// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonRotator.h"
#include "AdvancedUICommonRotator.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta = (DisableNaiveTick)) 
class ADVANCEDUI_API UAdvancedUICommonRotator : public UCommonRotator
{
	GENERATED_BODY()

public:
	void SetSelectedOptionByText(const FText& InTextOption);
	
};
