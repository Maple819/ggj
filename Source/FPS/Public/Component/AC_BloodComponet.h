// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_BloodComponet.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPS_API UAC_BloodComponet : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_BloodComponet();

	float MaxHealth = 100.f;
	float CurHealth = MaxHealth;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;



public:	

	UFUNCTION(BlueprintCallable, Category = "Health")
	void AddHealth(const float heal) {
		CurHealth = FMath::Clamp(CurHealth + heal, 0.f, MaxHealth);
	}

	UFUNCTION(BlueprintCallable, Category = "Health")
	void TakeDamage(const float damage) {
		CurHealth = FMath::Clamp(CurHealth - damage, 0.f, MaxHealth); 
	}

	UFUNCTION(BlueprintCallable, Category = "Health")
	bool IsDead() const {
		return CurHealth <= 0.f;
	}
		
};
