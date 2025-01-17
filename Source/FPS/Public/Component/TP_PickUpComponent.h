// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Character/FPSCharacter.h"
#include "GameplayTagsClasses.h"
#include "Data/DA_PickUpItemInfos.h"
#include "TP_PickUpComponent.generated.h"

// Declaration of the delegate that will be called when someone picks this up
// The character picking this up is the parameter sent with the notification
struct FPickUpItemInfo;
class UDA_PickUpItemInfos;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPickUp, AFPSCharacter*, PickUpCharacter, const FPickUpItemInfo&, ItemInfo);

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FPS_API UTP_PickUpComponent : public USphereComponent
{
	GENERATED_BODY()

public:
	
	/** Delegate to whom anyone can subscribe to receive this event */
	UPROPERTY(BlueprintAssignable, Category = "Interaction")
	FOnPickUp OnPickUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input|Info")
	FGameplayTag ItemTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input|Info")
	TObjectPtr<UDA_PickUpItemInfos> PickUpInfos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPickUpItemInfo ItemInfo;


	UTP_PickUpComponent();
protected:

	/** Called when the game starts */
	virtual void BeginPlay() override;

	/** Code for when something overlaps this component */
	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};