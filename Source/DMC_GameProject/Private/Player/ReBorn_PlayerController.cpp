// Fill out your copyright notice in the Description page of Project Settings.

#include "ReBorn_PlayerController.h"
#include "ReBorn_Character.h"

AReBorn_PlayerController::AReBorn_PlayerController()
{

}

void AReBorn_PlayerController::SetPawn(APawn* InPawn)
{
	AController::SetPawn(InPawn);
	ReBornCharacter = Cast<AReBorn_Character>(InPawn);
}

void AReBorn_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Movement
	InputComponent->BindAxis("MoveForward", this, &AReBorn_PlayerController::MoveForward);
	InputComponent->BindAxis("MoveBackward", this, &AReBorn_PlayerController::MoveBackward);
	InputComponent->BindAxis("TurnRight", this, &AReBorn_PlayerController::TurnRight);
	InputComponent->BindAxis("TurnLeft", this, &AReBorn_PlayerController::TurnLeft);
}

void AReBorn_PlayerController::MoveForward(float Value)
{
	if (ReBornCharacter != nullptr && Value != 0.0f)
	{
		ReBornCharacter->MoveForward(Value);
	}
}

void AReBorn_PlayerController::MoveBackward(float Value)
{
	MoveForward(Value * -1);
}

void AReBorn_PlayerController::TurnRight(float Value)
{
	if (ReBornCharacter != nullptr && Value != 0.0f)
	{
		ReBornCharacter->TurnRight(Value);
	}
}

void AReBorn_PlayerController::TurnLeft(float Value)
{
	TurnRight(Value * -1);
}

void AReBorn_PlayerController::Sprint()
{
	if (ReBornCharacter)
	{
		ReBornCharacter->Sprint();
	}
}

void AReBorn_PlayerController::StopSprinting()
{
	if (ReBornCharacter)
	{
		ReBornCharacter->StopSprinting();
	}
}
