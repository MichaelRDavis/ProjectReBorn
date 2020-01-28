// Fill out your copyright notice in the Description page of Project Settings.

#include "ReBorn_CharacterMovement.h"

UReBorn_CharacterMovement::UReBorn_CharacterMovement()
{
	MaxWalkSpeed = 180.0f;
	SprintSpeed = 360.0f;
	SprintAcceleration = 80.0f;
	bIsSprinting = false;
}

float UReBorn_CharacterMovement::GetMaxSpeed() const
{
	return bIsSprinting ? SprintSpeed : Super::GetMaxSpeed();
}

float UReBorn_CharacterMovement::GetMaxAcceleration() const
{
	return bIsSprinting ? SprintAcceleration : Super::GetMaxAcceleration();
}
