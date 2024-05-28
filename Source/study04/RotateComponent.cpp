// Fill out your copyright notice in the Description page of Project Settings.


#include "RotateComponent.h"

// Sets default values for this component's properties
URotateComponent::URotateComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URotateComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URotateComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (ShouldRotate)
	{
		FRotator CurrentRotation = GetOwner()->GetActorRotation();
		FRo

		/*FVector CurrentLocation = GetOwner()->GetActorLocation();
		FVector TargetLocation = OriginalLocation + MoveOffset;
		float MoveSpeed = FVector::Distance(OriginalLocation, TargetLocation) / MoveTime;

		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, NewDeltaMoveTime, MoveSpeed);
		GetOwner()->SetActorLocation(NewLocation);*/
	}
}

