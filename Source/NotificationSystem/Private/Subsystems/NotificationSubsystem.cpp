// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/NotificationSubsystem.h"

UNotificationSubsystem::UNotificationSubsystem()
{
}

void UNotificationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
}

void UNotificationSubsystem::Deinitialize()
{
}

void UNotificationSubsystem::PushNotification(FNotification Notification)
{
	Notifications.Push(Notification);

	if (OnPushNotification.IsBound())
	{
		OnPushNotification.Broadcast(Notification);
	}
}

bool UNotificationSubsystem::PopNotification(FNotification& Notification)
{
	if (Notifications.Num() > 0)
	{
		Notification = Notifications.Pop(true);

		if (OnPopNotification.IsBound())
		{
			OnPopNotification.Broadcast(Notification);
		}

		return true;
	}
	return false;
}
