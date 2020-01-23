// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ReBorn_PlayerController.generated.h"

class AReBorn_CameraActor;

UCLASS()
class DMC_GAMEPROJECT_API AReBorn_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AReBorn_PlayerController();

	UFUNCTION(BlueprintCallable, Category=PlayerController)
	void SwitchCamera(AReBorn_CameraActor* NewCamera);
};
