// Fill out your copyright notice in the Description page of Project Settings.

#include "ReBorn_BaseCharacter.h"
#include "Kismet/GameplayStatics.h"

AReBorn_BaseCharacter::AReBorn_BaseCharacter()
{
	GetMesh()->SetCollisionObjectType(ECC_Pawn);

	Health = 0;
	MaxHealth = 100;
}

void AReBorn_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (Health == 0)
	{
		Health = MaxHealth;
	}
}

float AReBorn_BaseCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	EventTakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	if (Damage <= 0.0f)
	{
		return 0.0f;
	}

	int32 ResultDamage = FMath::TruncToInt(Damage);
	if (ResultDamage > 0)
	{
		Health -= ResultDamage;
		if (Health <= 0)
		{
			Die();
		}
		else
		{
			
		}
	}

	return (float)ResultDamage;
}

void AReBorn_BaseCharacter::K2_TakeDamage(float Damage, TSubclassOf<UDamageType> DamageType, AController* EventInstigator, AActor* DamageCauser)
{
	TakeDamage(Damage, FPointDamageEvent(Damage, FHitResult(), FVector(0.0f, 0.0f, -1.0f), DamageType), EventInstigator, DamageCauser);
}

void AReBorn_BaseCharacter::EventTakeDamage_Implementation(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{

}

bool AReBorn_BaseCharacter::Die()
{
	if (bIsDead || IsPendingKill())
	{
		return false;
	}

	Health = FMath::Min(0, Health);

	PlayDeath();
	return false;
}

void AReBorn_BaseCharacter::PlayDeath()
{
	if (bIsDead)
	{
		return;
	}

	bIsDead = true;

	if (DeathSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation());
	}
}

void AReBorn_BaseCharacter::PlayHit()
{
	if (HitSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());
	}
}

void AReBorn_BaseCharacter::PlayRagdoll()
{
	if (IsPendingKill())
	{
		bInRagdoll = false;
	}
	else
	{
		bInRagdoll = true;
		GetMesh()->SetSimulatePhysics(true);
		GetMesh()->WakeAllRigidBodies();
		GetMesh()->bBlendPhysics = true;
	}

}

int32 AReBorn_BaseCharacter::GetHealth() const
{
	return Health;
}

int32 AReBorn_BaseCharacter::GetMaxHealth() const
{
	return MaxHealth;
}

bool AReBorn_BaseCharacter::IsDead() const
{
	return bIsDead;
}

