// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Player/ReBorn_BaseCharacter.h"
#include "ReBorn_Character.generated.h"

class AReBorn_InventoryItem;
class AReBorn_Weapon;
class UReBorn_CharacterMovement;

UCLASS()
class DMC_GAMEPROJECT_API AReBorn_Character : public AReBorn_BaseCharacter
{
	GENERATED_BODY()
	
public:
	AReBorn_Character();

	virtual void Destroyed() override;

private:
	/** Cached ReBornCharacterMovement */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Character, meta=(AllowPrivateAccess="true"))
	UReBorn_CharacterMovement* ReBornCharacterMovement;

public:
	/** Handles moving forward/backward */
	UFUNCTION(BlueprintCallable, Category = Pawn)
	virtual void MoveForward(float Value);

	/** Handles turning left and right */
	UFUNCTION(BlueprintCallable, Category = Pawn)
	virtual void TurnRight(float Rate);

	/** Make the character sprint on next update */
	UFUNCTION(BlueprintCallable, Category=Pawn)
	virtual void Sprint();

	/** Stop the character from sprinting */
	UFUNCTION(BlueprintCallable, Category=Pawn)
	virtual void StopSprinting();

	/** Returns true if character is currently sprinting */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=Pawn)
	bool IsSprinting() const;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Pawn)
	float BaseTurnRate;

	/** Add item to inventory */
	UFUNCTION(BlueprintCallable, Category = Pawn)
	virtual void AddItem(TSubclassOf<AReBorn_InventoryItem> ItemToAdd);

	/** Remove item from inventory */
	UFUNCTION(BlueprintCallable, Category = Pawn)
	virtual void RemoveItem(AReBorn_InventoryItem* ItemToRemove);

	/** Find item in inventory */
	UFUNCTION(BlueprintCallable, Category = Pawn)
	virtual AReBorn_InventoryItem* FindInventoryItem(TSubclassOf<AReBorn_InventoryItem> ItemClass);

	/** Remove all items from inventory and destroy them. */
	UFUNCTION(BlueprintCallable, Category = Pawn)
	virtual void DestroyInventory();

	/** Equips a weapon from the players inventory */
	UFUNCTION(BlueprintCallable, Category=Pawn)
	virtual void EquipWeapon(AReBorn_Weapon* NewWeapon);

	/** Switch weapon */
	UFUNCTION(BlueprintCallable, Category=Pawn)
	virtual void SwitchWeapon(AReBorn_Weapon* NewWeapon);

	/** Returns the currently equipped weapon */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=Pawn)
	AReBorn_Weapon* GetWeapon() const;

	/** Switches player camera view */
	UFUNCTION(BlueprintCallable, Category=Pawn)
	virtual void SwitchCamera(AActor* NewCamera);

protected:
	/** List of item in inventory */
	UPROPERTY(BlueprintReadOnly, Category=Pawn)
	TArray<AReBorn_InventoryItem*> Inventory;

	/** Currently equipped weapon */
	UPROPERTY(BlueprintReadOnly, Category=Pawn)
	AReBorn_Weapon* Weapon;

	/** Weapon pending equip */
	UPROPERTY(BlueprintReadOnly, Category=Weapon)
	AReBorn_Weapon* PendingWeapon;
};
