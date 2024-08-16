// Fill out your copyright notice in the Description page of Project Settings.


#include "ButtonComponent.h"

// Sets default values for this component's properties
UButtonComponent::UButtonComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UButtonComponent::BeginPlay()
{
	Super::BeginPlay();

	if (!CheckButtonReleased())
	{
		GetOwner()->Tags.Add("Released");
	}
}


// Called every frame
void UButtonComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UButtonComponent::ControlDoor()
{
	if (CheckOnInteract() && CheckButtonReleased())
	{
		SetIsUnlock(true);
		SetButtonVisual();
	}
}

bool UButtonComponent::CheckOnInteract()
{
	return GetOwner()->ActorHasTag("ON");
}

bool UButtonComponent::CheckButtonReleased()
{
	return GetOwner()->ActorHasTag("Released");
}

void UButtonComponent::SetButtonVisual()
{
	if (CheckButtonReleased())
	{
		GetOwner()->Tags.Remove("Released");
		
		CurrentButtonVector = GetOwner()->GetActorLocation();
		GetOwner()->SetActorLocation(CurrentButtonVector + ButtonVector);
	}
}

