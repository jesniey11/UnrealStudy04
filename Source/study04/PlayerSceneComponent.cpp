// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSceneComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "TimerManager.h"
#include "Components/InputComponent.h"

// Sets default values for this component's properties
UPlayerSceneComponent::UPlayerSceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerSceneComponent::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void UPlayerSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UPhysicsHandleComponent* PhysicsHandle = GetPhysicsHandle();
	if (PhysicsHandle == nullptr)
	{
		return;
	}

	if (PhysicsHandle->GetGrabbedComponent() != nullptr)
	{
		FVector TargetLocation = GetComponentLocation() + GetForwardVector() * HoldDistance;
		PhysicsHandle->SetTargetLocationAndRotation(TargetLocation, GetComponentRotation());
	}
}


void UPlayerSceneComponent::Grab()
{
	UPhysicsHandleComponent* PhysicsHandle = GetPhysicsHandle();
	if (PhysicsHandle == nullptr)
	{
		return;
	}

	FHitResult HitResult;
	bool HasHit = GetGrabbableInReach(HitResult);

	if (HasHit)
	{
		UPrimitiveComponent* HitComponent = HitResult.GetComponent();
		HitComponent->WakeAllRigidBodies();

		HitResult.GetActor()->Tags.Add("Grabbed");

		PhysicsHandle->GrabComponentAtLocationWithRotation(
			HitComponent,
			NAME_None,
			HitResult.ImpactPoint,
			GetComponentRotation()
		);

		/*
		AActor* HitActor = HitResult.GetActor();
		FString ActorName = HitActor->GetActorNameOrLabel();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ActorName);
		
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10, 10, FColor::Green, false, 5);
		//DrawDebugSphere(GetWorld(), HitResult.Location, 10, 10, FColor::Red, false, 5);
		*/
	}
}

void UPlayerSceneComponent::Release()
{
	UPhysicsHandleComponent* PhysicsHandle = GetPhysicsHandle();
	if (PhysicsHandle == nullptr)
	{
		return;
	}

	if (PhysicsHandle->GetGrabbedComponent() != nullptr)
	{
		AActor* GrabbedActor = PhysicsHandle->GetGrabbedComponent()->GetOwner();
		GrabbedActor->Tags.Remove("Grabbed");

		PhysicsHandle->ReleaseComponent();
	}
}

void UPlayerSceneComponent::Interact()
{
	UE_LOG(LogTemp, Warning, TEXT("E Pressed"));

	FHitResult HitResult;
	bool HasHit = GetGrabbableInReach(HitResult);
	
	if (HasHit)
	{
		AActor* HitActor = HitResult.GetActor();
		
		// 대상 액터가 Interact 가능 액터인지 확인
		if (HitActor->ActorHasTag("Interact"))
		{
			HitActor->Tags.Add("ON");
			

			UE_LOG(LogTemp, Display, TEXT(""));

			GetWorld()->GetTimerManager().SetTimer(
				TimerHandle, 
				FTimerDelegate::CreateLambda([this, HitActor]() 
					{
						HitActor->Tags.Remove("ON"); 
					}), 
				1.0f, 
				false
			);

		}
	}
}

UPhysicsHandleComponent* UPlayerSceneComponent::GetPhysicsHandle() const
{
	UPhysicsHandleComponent* Result = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (Result == nullptr) 
	{
		UE_LOG(LogTemp, Error, TEXT(" ""GrabComponent"" NEED UPhysicsHandleComponent"));
	}
	return Result;
}

bool UPlayerSceneComponent::GetGrabbableInReach(FHitResult& OutHitResult) const
{
	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * MaxGrabDistance;

	//DrawDebugLine(GetWorld(), Start, End, FColor::White);

	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);

	return GetWorld()->SweepSingleByChannel(
		OutHitResult,
		Start, End,
		FQuat::Identity,
		ECC_GameTraceChannel2,
		Sphere
	);	
}