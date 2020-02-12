// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "ReBorn_CameraTriggerBox.generated.h"

class AReBorn_CameraActor;

UCLASS()
class DMC_GAMEPROJECT_API AReBorn_CameraTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

public:
	AReBorn_CameraTriggerBox();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Trigger)
	AReBorn_CameraActor* Camera;
};
