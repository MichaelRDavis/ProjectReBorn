// Fill out your copyright notice in the Description page of Project Settings.

#include "ReBorn_Weapon.h"

AReBorn_Weapon::AReBorn_Weapon()
{
	Ammo = 0;
	MaxAmmo = 100;
	FireRate = 0.2f
}

void AReBorn_Weapon::GetAmmo()
{
	if (ReBornOwner)
	{
		// Retrieves ammo from the players inventory via the ammo class type
		AReBorn_Ammo* AmmoType = ReBornOwner->FindInventoryItem(AmmoClass);
		if (AmmoType)
		{
			MagazineAmmo = AmmoType->MagazineAmount;
			Ammo = AmmoType->MagazineAmount * AmmoType->MagazineCount;
		}
	}
}

void AReBorn_Weapon::ConsumeAmmo()
{
	Ammo--;
}
