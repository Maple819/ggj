// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/AC_Backpack.h"

// Sets default values for this component's properties
UAC_Backpack::UAC_Backpack()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UAC_Backpack::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

bool UAC_Backpack::AddItemInBackpack(const FPickUpItemInfo& item, const FGameplayTag& tag)
{
	if (item.ItemTag.MatchesTag(tag) ){
		ItemsInBackpack.Add(item);
		return true;
	}
	return false;
}

bool UAC_Backpack::RemoveItemInBackpack(const FGameplayTag& tag)
{
	for (int32 i = 0; i < ItemsInBackpack.Num(); ++i)
	{
		if (ItemsInBackpack[i].ItemTag.MatchesTagExact(tag))
		{
			ItemsInBackpack.RemoveAt(i);
			return true;
		}
	}
	return false;
}

