// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/ReBorn_InventoryItem.h"
#include "ReBorn_Ammo.generated.h"

UENUM(BlueprintType)
enum class EAmmoType : uint8
{
	EBullet,
	EShell
};

UCLASS()
class DMC_GAMEPROJECT_API AReBorn_Ammo : public AReBorn_InventoryItem
{
	GENERATED_BODY()
	
public:
	AReBorn_Ammo();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ammo)
	int32 MagazineAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ammo)
	int32 MagazineCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pawn)
	EAmmoType AmmoType;
};
