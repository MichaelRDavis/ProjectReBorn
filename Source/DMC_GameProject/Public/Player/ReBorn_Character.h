// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Player/ReBorn_BaseCharacter.h"
#include "ReBorn_Character.generated.h"

class AReBorn_InventoryItem;

UCLASS()
class DMC_GAMEPROJECT_API AReBorn_Character : public AReBorn_BaseCharacter
{
	GENERATED_BODY()
	
public:
	AReBorn_Character();

	virtual void Destroyed() override;

	/** Handles moving forward/backward */
	UFUNCTION(BlueprintCallable, Category = Pawn)
	virtual void MoveForward(float Value);

	/** Handles turning left and right */
	UFUNCTION(BlueprintCallable, Category = Pawn)
	virtual void TurnRight(float Rate);

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Pawn)
	float BaseTurnRate;

	UFUNCTION(BlueprintCallable, Category = Pawn)
	virtual void AddItem(TSubclassOf<AReBorn_InventoryItem> ItemToAdd);

	UFUNCTION(BlueprintCallable, Category = Pawn)
	virtual void RemoveItem(AReBorn_InventoryItem* ItemToRemove);

	UFUNCTION(BlueprintCallable, Category = Pawn)
	virtual AReBorn_InventoryItem* FindInventoryItem(TSubclassOf<AReBorn_InventoryItem> ItemClass);

	UFUNCTION(BlueprintCallable, Category = Pawn)
	virtual void DestroyInventory();

protected:
	UPROPERTY()
	TArray<AReBorn_InventoryItem*> Inventory;
};
