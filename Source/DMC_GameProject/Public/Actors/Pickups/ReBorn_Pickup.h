// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Actors/ReBorn_InteractiveActor.h"
#include "ReBorn_Pickup.generated.h"

UCLASS()
class DMC_GAMEPROJECT_API AReBorn_Pickup : public AReBorn_InteractiveActor
{
	GENERATED_BODY()
	
public:
	AReBorn_Pickup();

	virtual void OnUse(AReBorn_Character* Pawn) override;

	/** Sound to play on pickup */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=Pickup)
	USoundBase* PickupSound;
};
