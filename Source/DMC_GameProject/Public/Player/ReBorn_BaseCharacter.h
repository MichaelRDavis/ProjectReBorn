// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ReBorn_BaseCharacter.generated.h"

UCLASS()
class DMC_GAMEPROJECT_API AReBorn_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AReBorn_BaseCharacter();

	virtual void BeginPlay() override;
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintCallable, Category = Pawn, meta = (DisplayName = "Take Damage"))
	virtual void K2_TakeDamage(float Damage, TSubclassOf<UDamageType> DamageType, AController* EventInstigator, AActor* DamageCauser);

	UFUNCTION(BlueprintImplementableEvent, Category = Pawn)
	void EventTakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);
	void EventTakeDamage_Implementation(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);

	/** Kills this pawn, when we run out of health. */
	UFUNCTION(BlueprintCallable, Category = Pawn)
	virtual bool Die();

	UFUNCTION(BlueprintCallable, Category = Pawn)
	virtual void PlayDeath();

	UFUNCTION(BlueprintCallable, Category = Pawn)
	virtual void PlayHit();

	UFUNCTION(BlueprintCallable, Category = Pawn)
	virtual void PlayRagdoll();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Pawn)
	int32 GetHealth() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Pawn)
	int32 GetMaxHealth() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Pawn)
	bool IsDead() const;

protected:
	/** Current health of the pawn */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Pawn)
	int32 Health;

	/** Max health of the pawn */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pawn)
	int32 MaxHealth;

	/** True if pawn is in it's dying state */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Pawn)
	bool bIsDead;

	/** True if pawn is it's ragdoll state */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Pawn)
	bool bInRagdoll;

	/** Sound played on death */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Pawn)
	USoundBase* DeathSound;

	/** Sound played on hit */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Pawn)
	USoundBase* HitSound;
};
