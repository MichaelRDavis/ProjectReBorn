// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ReBorn_CharacterMovement.generated.h"

UCLASS()
class DMC_GAMEPROJECT_API UReBorn_CharacterMovement : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UReBorn_CharacterMovement();

	/** The maximum speed when sprinting */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprint")
	float SprintSpeed;

	/** Max acceleration when sprinting */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sprint")
	float SprintAcceleration;

	/** True if currently sprinting */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Sprint")
	bool bIsSprinting;

	virtual float GetMaxSpeed() const override;
	virtual float GetMaxAcceleration() const override;
};
