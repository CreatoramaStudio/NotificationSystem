// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "NotificationStructs.generated.h"

USTRUCT(BlueprintType)
struct NOTIFICATIONSYSTEM_API FNotification
{
    GENERATED_BODY()

public:

    UPROPERTY(SaveGame, EditAnywhere,BlueprintReadWrite, Category="Notification System")
    FGameplayTag CategoryTag;

    UPROPERTY(SaveGame, EditAnywhere, BlueprintReadWrite, Category = "Notification System")
    FText Name;

    UPROPERTY(SaveGame, EditAnywhere, BlueprintReadWrite, Category = "Notification System",meta = (MultiLine = true))
    FText Description;
};
