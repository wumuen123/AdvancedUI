// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonTabListWidgetBase.h"
#include "AdvancedUITabListWidgetBase.generated.h"

/**
 * 
 */
class UAdvancedUICommonButtonBase;

UCLASS(Abstract, BlueprintType, meta = (DisableNaiveTick))
class ADVANCEDUI_API UAdvancedUITabListWidgetBase : public UCommonTabListWidgetBase
{
	GENERATED_BODY()
public:
	void RequestRegisterTab(const FName& InTabID, const FText& InTabDisplayName);
private:

	//~ Begin UWidget Interface
#if WITH_EDITOR	
	virtual void ValidateCompiledDefaults(class IWidgetCompilerLog& CompileLog) const override;
#endif
	//~ End UWidget Interface
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Advanced UI Tab List Settings", meta = (AllowPrivateAccess = "true", ClampMin = "0", ClampMax = "10"))
	int32 DebugEditorPreviewTabCount = 3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Advanced UI Tab List Settings", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UAdvancedUICommonButtonBase> TabButtonEntryWidgetClass;

};
