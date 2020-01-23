// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReBorn_InteractiveActor.generated.h"

class AReBorn_Character;

UCLASS()
class DMC_GAMEPROJECT_API AReBorn_InteractiveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AReBorn_InteractiveActor();

	UFUNCTION(BlueprintImplementableEvent)
	void EventOnUse(AReBorn_Character* Pawn);
	void EventOnUse_Implementation(AReBorn_Character* Pawn);

	virtual void OnUse(AReBorn_Character* Pawn);
};
