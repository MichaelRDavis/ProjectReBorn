// Fill out your copyright notice in the Description page of Project Settings.

#include "ReBorn_Character.h"
#include "ReBorn_InventoryItem.h"

AReBorn_Character::AReBorn_Character()
{
	BaseTurnRate = 75.0f;
}

void AReBorn_Character::Destroyed()
{
	Super::Destroyed();

	DestroyInventory();
}

void AReBorn_Character::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// Find put which way is forward
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

		// Add movement in forward direction
		AddMovementInput(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X), Value);
	}
}

void AReBorn_Character::TurnRight(float Rate)
{
	if (Rate != 0.0f)
	{
		AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
	}
}

void AReBorn_Character::AddItem(TSubclassOf<AReBorn_InventoryItem> ItemToAdd)
{
	if (ItemToAdd)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		AReBorn_InventoryItem* NewItem = GetWorld()->SpawnActor<AReBorn_InventoryItem>(ItemToAdd, SpawnParams);
		NewItem->GiveTo(this);
		Inventory.AddUnique(NewItem);
	}
}

void AReBorn_Character::RemoveItem(AReBorn_InventoryItem* ItemToRemove)
{
	if (ItemToRemove)
	{
		ItemToRemove->Remove();
		Inventory.RemoveSingle(ItemToRemove);
	}
}

AReBorn_InventoryItem* AReBorn_Character::FindInventoryItem(TSubclassOf<AReBorn_InventoryItem> ItemClass)
{
	for (int32 i = 0; i < Inventory.Num(); i++)
	{
		if (Inventory[i] && Inventory[i]->IsA(ItemClass))
		{
			return Inventory[i];
		}
	}

	return nullptr;
}

void AReBorn_Character::DestroyInventory()
{

}
