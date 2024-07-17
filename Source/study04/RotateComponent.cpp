// Fill out your copyright notice in the Description page of Project Settings.


#include "RotateComponent.h"
#include "Math/UnrealMathUtility.h"

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

	RotatorTranslator();
}


// Called every frame
void URotateComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void URotateComponent::OpenDoor()
{
	FRotator CurrentRotation = GetOwner()->GetActorRotation();
	FRotator TargetRotation = OriginalRotation + RotateOffset;

	float RotateSpeed = OriginalRotation.GetManhattanDistance(TargetRotation) / Time;

	FRotator NewRotation = FMath::RInterpConstantTo(CurrentRotation, TargetRotation, TickTime, RotateSpeed);
	GetOwner()->SetActorRotation(NewRotation);
}

void URotateComponent::CloseDoor()
{
	FRotator CurrentRotation = GetOwner()->GetActorRotation();
	FRotator TargetRotation = OriginalRotation;

	float RotateSpeed = TargetRotation.GetManhattanDistance(CurrentRotation) / Time * 1.5;

	FRotator NewRotation = FMath::RInterpConstantTo(CurrentRotation, TargetRotation, TickTime, RotateSpeed);
	GetOwner()->SetActorRotation(NewRotation);
}

void URotateComponent::RotatorTranslator()
{
	OriginalRotation = OriginalTransform.GetRotation().Rotator();
	RotateOffset = Offset.GetRotation().Rotator();
}