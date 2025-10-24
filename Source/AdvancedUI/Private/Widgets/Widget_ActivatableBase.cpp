// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Widget_ActivatableBase.h"
#include "Controllers/AdvancedUIPlayerController.h"

AAdvancedUIPlayerController* UWidget_ActivatableBase::GetOwningAdvancedUIPlayerController()
{
    if (!CachedOwningAdvancedUIPC.IsValid()) {
        CachedOwningAdvancedUIPC = GetOwningPlayer<AAdvancedUIPlayerController>();
    }

    return CachedOwningAdvancedUIPC.IsValid() ? CachedOwningAdvancedUIPC.Get() : nullptr;
}
