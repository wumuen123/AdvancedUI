// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncActions/AsyncAction_PushConfirmScreen.h"
#include "Subsystems/AdvancedUISubsystem.h"

UAsyncAction_PushConfirmScreen* UAsyncAction_PushConfirmScreen::PushConfirmScreen(const UObject* WorldContextObject, EConfirmScreenType InScreenType, FText InScreenTitle, FText InScreenMessage)
{
    if (GEngine) {
        if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull)) {
            UAsyncAction_PushConfirmScreen* Node = NewObject<UAsyncAction_PushConfirmScreen>();
            Node->CachedOwningWorld = World;
            Node->CachedScreenType = InScreenType;
            Node->CachedScreenTitle = InScreenTitle;
            Node->CachedScreenMessage = InScreenMessage;

            Node->RegisterWithGameInstance(World);

            return Node;
        }
    }
    return nullptr;
}

void UAsyncAction_PushConfirmScreen::Activate()
{
    UAdvancedUISubsystem::Get(CachedOwningWorld.Get())->PushConfirmScreenToModalStackAynsc(
        CachedScreenType,
        CachedScreenTitle,
        CachedScreenMessage,
        [this](EConfirmScreenButtonType ButtonType) {
            OnButtonClickDelegate.Broadcast(ButtonType);

            // Destroy our async action, otherwise it won't self-destroy
            SetReadyToDestroy();
        }
    );
}
