// Fill out your copyright notice in the Description page of Project Settings.

#include "ReBorn_Pickup.h"
#include "Kismet/GameplayStatics.h"

AReBorn_Pickup::AReBorn_Pickup()
{

}

void AReBorn_Pickup::OnUse(AReBorn_Character* Pawn)
{
	if (PickupSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, PickupSound, GetActorLocation());
	}
}
