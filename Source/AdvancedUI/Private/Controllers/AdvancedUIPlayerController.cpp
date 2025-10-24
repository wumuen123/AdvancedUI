// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/AdvancedUIPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

void AAdvancedUIPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	TArray<AActor*> FoundCameras;
	UGameplayStatics::GetAllActorsOfClassWithTag(this, ACameraActor::StaticClass(), FName("Default"), FoundCameras);
	if (!FoundCameras.IsEmpty()) {
		SetViewTarget(FoundCameras[0]);
	}
}
