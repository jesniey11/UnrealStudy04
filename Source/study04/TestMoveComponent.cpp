// Fill out your copyright notice in the Description page of Project Settings.


#include "TestMoveComponent.h"

// Sets default values for this component's properties
UTestMoveComponent::UTestMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTestMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	VectorTranslator();
}


// Called every frame
void UTestMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTestMoveComponent::VectorTranslator()
{
	OriginalVector = OriginalTransform.GetLocation();
	VectorOffset = Offset.GetLocation();
}

void UTestMoveComponent::OpenDoor()
{
	FVector CurrentLocation = GetOwner()->GetActorLocation();
	FVector TargetLocation = OriginalVector + VectorOffset;

	float MoveSpeed = FVector::Distance(OriginalVector, TargetLocation) / Time;

	FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, TickTime, MoveSpeed);
	GetOwner()->SetActorLocation(NewLocation);
}
