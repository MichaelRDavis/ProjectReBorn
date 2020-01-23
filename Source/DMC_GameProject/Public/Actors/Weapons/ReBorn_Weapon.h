// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/ReBorn_InventoryItem.h"
#include "ReBorn_Weapon.generated.h"

class AReBorn_Ammo;

UENUM(BlueprintType)
enum class EWeaponState : uint8
{
	EIdle,
	EFiring,
	EReloading,
	EEquipping
};

UCLASS()
class DMC_GAMEPROJECT_API AReBorn_Weapon : public AReBorn_InventoryItem
{
	GENERATED_BODY()

public:
	AReBorn_Weapon();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Mesh)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	TSubclassOf<AReBorn_Ammo> AmmoClass;

	/** Current ammo */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	int32 Ammo;

	/** Max ammo */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	int32 MaxAmmo;
};
