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

	AActor* Parent = GetOwner()->GetParentActor();
	OriginalRotation = GetOwner()->GetActorRotation();

	UnlockComponent = GetUnlockComponent(Parent);
}


// Called every frame
void URotateComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	if (UnlockComponent->GetIsUnlock())
	{
		FRotator CurrentRotation = GetOwner()->GetActorRotation();
		FRotator TargetRotation = OriginalRotation + RotateOffset;

		float RotateSpeed = OriginalRotation.GetManhattanDistance(TargetRotation) / RotateTime;

		FRotator NewRotation = FMath::RInterpConstantTo(CurrentRotation, TargetRotation, DeltaTime, RotateSpeed);
		GetOwner()->SetActorRotation(NewRotation);
	}
}

UUnlockComponent* URotateComponent::GetUnlockComponent(AActor* ParentActor) const
{
	if (UnlockComponent) { return UnlockComponent; }

	if (ParentActor)
	{
		return ParentActor->FindComponentByClass<UUnlockComponent>();
	}

	return nullptr;
}