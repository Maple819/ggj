// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Data/DA_PickUpItemInfos.h"
#include "AC_Backpack.generated.h"

struct FPickUpItemInfo;

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FPS_API UAC_Backpack : public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite);
	TArray<FPickUpItemInfo> ItemsInBackpack;

	// Sets default values for this component's properties
	UAC_Backpack();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	bool AddItemInBackpack(const FPickUpItemInfo& item, const FGameplayTag& tag);

	UFUNCTION(BlueprintCallable)
	bool RemoveItemInBackpack(const FGameplayTag& tag);

};