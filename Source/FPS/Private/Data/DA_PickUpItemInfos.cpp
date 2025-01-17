// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/DA_PickUpItemInfos.h"

FPickUpItemInfo UDA_PickUpItemInfos::FindItemInfoByTag(const FGameplayTag& tag) const
{
	for (const FPickUpItemInfo& item : PickUpItemInfos) {
		if (item.ItemTag.MatchesTagExact(tag)) {
			return item;
		}
	}
	return FPickUpItemInfo();
}
