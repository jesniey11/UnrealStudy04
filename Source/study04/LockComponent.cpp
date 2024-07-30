// Fill out your copyright notice in the Description page of Project Settings.


#include "LockComponent.h"

// Sets default values for this component's properties
ULockComponent::ULockComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void ULockComponent::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ULockComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	ControlDoor();
}

AActor* ULockComponent::GetAcceptableKey() const
{
	TArray<AActor*> OverlappingActors;
	GetOverlappingActors(OverlappingActors);

	for (AActor* Actor : OverlappingActors)
	{
		bool HasAcceptableTag = Actor->ActorHasTag(AcceptableActorTag);
		bool IsGrabbed = Actor->ActorHasTag("Grabbed");

		if (HasAcceptableTag && !IsGrabbed)
		{
			return Actor;
		}
	}
	return nullptr;
}

void ULockComponent::DestroyKey(AActor* Key)
{
	if (CanDestroyKey)
	{
		Key->Destroy();
	}
}

bool ULockComponent::GetIsUnlock() const
{
	return IsUnlock;
}

void ULockComponent::SetIsUnlock(bool NewIsUnlock)
{
	IsUnlock = NewIsUnlock;
}

bool ULockComponent::GetIsToggleable() const
{
	return IsToggleable;
}

void ULockComponent::ControlDoor()
{
	AActor* Key = GetAcceptableKey();

	if (Key)
	{
		FString Name = Key->GetActorNameOrLabel();
		UE_LOG(LogTemp, Display, TEXT("Get KEY %s"), *Name);

		SetIsUnlock(true);

		if (!IsToggleable)
		{
			DestroyKey(Key);
		}
	}

	else
	{
		if (IsToggleable)
		{
			SetIsUnlock(false);
		}
	}
}