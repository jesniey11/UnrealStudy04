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
		FString debug = Actor->GetActorNameOrLabel();
		UE_LOG(LogTemp, Display, TEXT("KEY: %s"), *debug);
		
		// AActor* Actor(KEY)를 Destroy
		// Owner의 Physics Simulate 활성화(SetSimulatePhysics(true))
		// => 블루프린트에서 처리

		debug = GetOwner()->GetActorNameOrLabel();
		UE_LOG(LogTemp, Display, TEXT("LOCK: %s"), *debug);

		IsUnlock = true;

		// 이 IsUnlock을 다른 액터의 Move/Rotate로 보내야함
		// => Door 액터에서 Lock(여기)의 IsUnlock에 접근 가능해야 함
		// => 델리게이트로 IsUnlock을 받아와야 함
		// => 델리게이트가 GetIsUnlock 을 바인딩
		// => 그러려면 GetIsUnlock이 여기 있어야함


		// Move/Rotate에서 GetUnlock으로 IsUnlock을 받음

		// Trigger에서 Delegate에 접근(IsUnlock 전달)
		// Move/Rotate에서 Delegate에 접근(IsUnlock 받음)
		// 같은 Lock-Door 연결 태그를 가지고 있음


		// 다른 Actor에 있는 Component->SetShould(true)

		// Move가 있으면 Move 활성
		/*if (Actor->FindComponentByClass<Move>())
		{
			
		}*/
		// Rotate가 있으면 Rotate 활성

		//unused
		/*
		UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
		if (Component != nullptr) 
		{
			Component->SetSimulatePhysics(false);
		}
		Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
		*/

		//MoveComponent->SetShouldMove(true);
	}
	else 
	{
		//MoveComponent->SetShouldMove(false); 
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

bool UTriggerComponent::GetIsUnlock() const
{
	return IsUnlock;
}