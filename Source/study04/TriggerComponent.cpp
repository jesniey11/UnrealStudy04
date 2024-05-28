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
	
}

// Called every frame
void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	AActor* Actor = GetAcceptableActor();
	
	if (Actor != nullptr) 
	{
		FString name = Actor->GetActorNameOrLabel();
		UE_LOG(LogTemp, Display, TEXT("%s"), *name);
		/*UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
		if (Component != nullptr) 
		{
			Component->SetSimulatePhysics(false);
		}*/
		//Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
		//MoveComponent->SetShouldMove(true);
		//UE_LOG(LogTemp, Display, TEXT("SetShouldMove(true)"));
	}
	else 
	{
		//MoveComponent->SetShouldMove(false); 
		//UE_LOG(LogTemp, Display, TEXT("SetShouldMove(false)"));
	}
}

void UTriggerComponent::SetMoveComponent(UMoveComponent* NewMoveComponent) 
{
	MoveComponent = NewMoveComponent;

}

AActor* UTriggerComponent::GetAcceptableActor() const 
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