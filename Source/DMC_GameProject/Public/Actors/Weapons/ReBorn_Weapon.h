// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "ReBorn_InventoryItem.h"
#include "ReBorn_Ammo.h"
#include "ReBorn_Weapon.generated.h"

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

	/** Weapon mesh */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Mesh)
	USkeletalMeshComponent* Mesh;

	/** Ammo type for weapon */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	TSubclassOf<AReBorn_Ammo> AmmoClass;

	/** Current ammo */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	int32 Ammo;

	/** Max ammo */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	int32 MaxAmmo;

	/** Current magazine size */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Weapon)
	int32 MagazineAmmo;

	/** Retrieves ammo from the players inventory */
	UFUNCTION(BlueprintCallable, Category=Weapon)
	void GetAmmo();

	/** Consumes ammo */
	UFUNCTION(BlueprintCallable, Category=Weapon)
	void ConsumeAmmo();

	/** Fire rate, the time between consecutive shots */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Weapon)
	float FireRate;

	/** Weapon spread in degrees */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Weapon)
	float Spread;

	/** Aiming weapon spread */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Weapon)
	float AimingSpread;

	/** Max range of weapon tracer */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Weapon)
	float MaxTracerDistance;

	/** Damage applied on hit */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Weapon)
	int32 HitDamage;
};
