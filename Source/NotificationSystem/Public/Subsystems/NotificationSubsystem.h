// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Data/NotificationStructs.h"
#include "NotificationSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNotificationMulticast, FNotification, Notification);

/**
 * 
 */
UCLASS()
class NOTIFICATIONSYSTEM_API UNotificationSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, Category = "Notification System|Event")
		FOnNotificationMulticast OnPushNotification;

	UPROPERTY(BlueprintAssignable, Category = "Notification System|Event")
		FOnNotificationMulticast OnPopNotification;

protected:

	UPROPERTY(SaveGame)
		TArray<FNotification> Notifications;

private:

public:

	UNotificationSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Notification System")
		void PushNotification(FNotification Notification);

	UFUNCTION(BlueprintCallable, Category = "Notification System")
		bool PopNotification(FNotification& Notification);

protected:

private:

};
