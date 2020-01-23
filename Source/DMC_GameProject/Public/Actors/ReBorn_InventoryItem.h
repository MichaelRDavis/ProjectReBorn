// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReBorn_InventoryItem.generated.h"

class AReBorn_Character;

UCLASS(Abstract, Blueprintable)
class DMC_GAMEPROJECT_API AReBorn_InventoryItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AReBorn_InventoryItem();

	/**  */
	UFUNCTION(BlueprintImplementableEvent, Category = Inventory)
	void EventGiveTo(AReBorn_Character* NewOwner);
	void EventGiveTo_Implementation(AReBorn_Character* NewOwner);

	/** Give inventory item to a new owner */
	UFUNCTION(BlueprintCallable, Category = Inventory)
	virtual void GiveTo(AReBorn_Character* NewOwner);

	/**  */
	UFUNCTION(BlueprintImplementableEvent, Category = Inventory)
	void EventRemove();
	void EventRemove_Implementation();

	/** Remove inventory item from owner */
	UFUNCTION(BlueprintCallable, Category = Inventory)
	virtual void Remove();

	/** Get owner of inventory item */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Inventory)
	AReBorn_Character* GetReBornOwner() const;

protected:
	/** Owner of inventory item */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Inventory)
	AReBorn_Character* ReBornOwner;

	/** Name of item */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	FName ItemName;

	/** Item description */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	FName ItemDescription;

	/** Item thumbnail texture */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	UTexture2D* ItemTexture;

	/** True if item can stack */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	bool bCanStack;

	/** Current stack count */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Inventory)
	int32 CurrentStackCount;

	/** Max item stack count */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	int32 MaxStackCount;

	/** True if this item can be consumed by the player */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	bool bIsConsumable;
};
