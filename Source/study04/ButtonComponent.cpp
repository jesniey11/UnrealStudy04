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

	// ...
	
}

void UButtonComponent::ControlDoor()
{
	SetLockState(true);
}
