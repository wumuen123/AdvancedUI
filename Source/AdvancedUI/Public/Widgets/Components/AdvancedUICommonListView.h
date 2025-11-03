// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonListView.h"
#include "AdvancedUICommonListView.generated.h"

class UDataAsset_DataListEntryMapping;
/**
 * 
 */
UCLASS()
class ADVANCEDUI_API UAdvancedUICommonListView : public UCommonListView
{
	GENERATED_BODY()

protected:
	// ~Begin UCommonListView Interface
	virtual UUserWidget& OnGenerateEntryWidgetInternal(UObject* Item, TSubclassOf<UUserWidget> DesiredEntryClass, const TSharedRef<STableViewBase>& OwnerTable) override;
	// ~End UCommonListView Interface

private:
#if WITH_EDITOR	
	virtual void ValidateCompiledDefaults(class IWidgetCompilerLog& CompileLog) const override;
#endif
	UPROPERTY(EditAnywhere, Category="AdvancedUI List View Settings")
	UDataAsset_DataListEntryMapping* DataListEntryMapping;
};
