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

	OriginalRotation = GetOwner()->GetActorRotation();
	UE_LOG(LogTemp, Warning, TEXT("Test: %s"), *OriginalRotation.ToString());
	
}


// Called every frame
void URotateComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (ShouldRotate)
	{
		FRotator CurrentRotation = GetOwner()->GetActorRotation();
		FRotator TargetRotation = OriginalRotation + RotateOffset;

		//UE_LOG(LogTemp, Display, TEXT("Offset: %s"), *RotateOffset.ToString());
		//UE_LOG(LogTemp, Display, TEXT("Current: %s"), *CurrentRotation.ToString());

		float RotateSpeed = OriginalRotation.GetManhattanDistance(TargetRotation) / RotateTime;

		FRotator NewRotation = FMath::RInterpConstantTo(CurrentRotation, TargetRotation, DeltaTime, RotateSpeed);
		GetOwner()->SetActorRotation(NewRotation);
	}
}

//void URotateComponent::SetShouldRotate(bool NewShouldRotate) 
//{
//	if (NewShouldRotate != NULL) 
//	{
//		ShouldRotate = NewShouldRotate;
//	}
//
//	else 
//	{
//		//UE_LOG(LogTemp, Error, TEXT("null NewShouldRotate"));
//		NewShouldRotate = ShouldRotate;
//	}
//}