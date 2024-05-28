// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveComponent.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMoveComponent::UMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();
	
	OriginalLocation = GetOwner()->GetActorLocation();
	
}

// Called every frame
void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (ShouldMove)
	{
		FVector CurrentLocation = GetOwner()->GetActorLocation();
		FVector TargetLocation = OriginalLocation + MoveOffset;
		float MoveSpeed = FVector::Distance(OriginalLocation, TargetLocation) / MoveTime;

		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, MoveSpeed);
		GetOwner()->SetActorLocation(NewLocation);
	}
}

//void UMoveComponent::SetShouldMove(bool NewShouldMove) 
//{
//	if (NewShouldMove != NULL) 
//	{
//		ShouldMove = NewShouldMove;
//	}
//
//	else 
//	{
//		//UE_LOG(LogTemp, Error, TEXT("null NewShouldMove"));
//		NewShouldMove = ShouldMove;
//	}
//}

//void UMoveComponent::Rotate(float NewDeltaRotateTime)
//{
//
//}
//
//void UMoveComponent::SetShouldRotate(bool NewShouldRotate)
//{
//	ShouldRotate = NewShouldRotate;
//}