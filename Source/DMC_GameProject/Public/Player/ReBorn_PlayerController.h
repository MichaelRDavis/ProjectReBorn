// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ReBorn_PlayerController.generated.h"

class AReBorn_Character;

UCLASS()
class DMC_GAMEPROJECT_API AReBorn_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AReBorn_PlayerController();

	virtual void SetPawn(APawn* InPawn) override;
	virtual void SetupInputComponent() override;

private:
	/** Character possessed by this controller */
	UPROPERTY(Transient)
	AReBorn_Character* ReBornCharacter;

protected:
	/** Handles moving forward */
	virtual void MoveForward(float Value);

	/** Handles moving backward */
	virtual void MoveBackward(float Value);

	/** Handles turning right */
	virtual void TurnRight(float Value);

	/** Handles turning left */
	virtual void TurnLeft(float Value);

	/** Sprinting */
	virtual void Sprint();
	virtual void StopSprinting();
};
