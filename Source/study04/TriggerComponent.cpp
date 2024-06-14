// Fill out your copyright notice in the Description page of Project Settings.

#include "TriggerComponent.h"

// Sets default values for this component's properties
UTriggerComponent::UTriggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
	UnlockComponent = GetUnlockComponent(Door);
}

// Called every frame
void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	ControlDoor(GetAcceptableKey());
}

AActor* UTriggerComponent::GetAcceptableKey() const 
{
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);

	for (AActor* Actor : Actors)
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

UUnlockComponent* UTriggerComponent::GetUnlockComponent(AActor* DoorActor) const
{	
	if (UnlockComponent)
	{
		return UnlockComponent;
	}

	if (DoorActor)
	{
		return DoorActor->FindComponentByClass<UUnlockComponent>();
	}

	return UnlockComponent;
}

void UTriggerComponent::ControlDoor(AActor* Key)
{
	if (Key)
	{
		SetLockState(true);
	}
}

void UTriggerComponent::GetInteraction()
{
	SetLockState(true);
}

void UTriggerComponent::SetLockState(bool State)
{
	if (UnlockComponent)
	{
		UnlockComponent->SetIsUnlock(State);
	}
}