// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/DataAssetBase.h"
#include "GameplayTagsClasses.h"
#include "DA_PickUpItemInfos.generated.h"

USTRUCT(BlueprintType)
struct FPickUpItemInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemCount = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTexture2D> ItemIcon = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ItemDescripition = FText();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag ItemTag = FGameplayTag();

	FPickUpItemInfo() {};
	FPickUpItemInfo(int cnt, UTexture2D& icon, FText des, FGameplayTag tag) : ItemCount(cnt), ItemIcon(icon), ItemDescripition(des), ItemTag(tag) {};
};


/**
 * 
 */
UCLASS()
class FPS_API UDA_PickUpItemInfos : public UDataAssetBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FPickUpItemInfo> PickUpItemInfos;

	FPickUpItemInfo FindItemInfoByTag(const FGameplayTag& tag) const;
	
};
