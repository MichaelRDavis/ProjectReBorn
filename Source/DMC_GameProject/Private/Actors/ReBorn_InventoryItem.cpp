// Fill out your copyright notice in the Description page of Project Settings.

#include "ReBorn_InventoryItem.h"
#include "ReBorn_Character.h"

AReBorn_InventoryItem::AReBorn_InventoryItem()
{

}

void AReBorn_InventoryItem::EventGiveTo_Implementation(AReBorn_Character* NewOwner)
{

}

void AReBorn_InventoryItem::GiveTo(AReBorn_Character* NewOwner)
{
	Instigator = NewOwner;
	SetOwner(NewOwner);
	ReBornOwner = NewOwner;
	EventGiveTo(NewOwner);
}

void AReBorn_InventoryItem::EventRemove_Implementation()
{

}

void AReBorn_InventoryItem::Remove()
{
	EventRemove();
	Instigator = nullptr;
	SetOwner(nullptr);
	ReBornOwner = nullptr;
}

AReBorn_Character* AReBorn_InventoryItem::GetReBornOwner() const
{
	return ReBornOwner;
}

