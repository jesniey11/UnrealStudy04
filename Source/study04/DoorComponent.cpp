Fill out your copyright notice in the Description page of Project Settings.


#include "DoorComponent.h"

// Sets default values for this component's properties
UDoorComponent::UDoorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorComponent::BeginPlay()
{
	Super::BeginPlay();

	GetLockComponent();
	GetOriginalTransform();
}


// Called every frame
void UDoorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	OpenDoor();
}

void UDoorComponent::GetLockComponent()
{
	UE_LOG(LogTemp, Display, TEXT("진입"));

	for (AActor* Lock : Locks)
	{
		ULockComponent* LockComponent = Lock->FindComponentByClass<ULockComponent>();

		if (!LockComponent)
		{
			FString Name = Lock->GetActorNameOrLabel();
			UE_LOG(LogTemp, Warning, TEXT("%s: NO Lock Component"), *Name);
		}

		else
		{
			LockComponents.Add(LockComponent);
			UE_LOG(LogTemp, Warning, TEXT("LockComponents SIZE - %d "), LockComponents.Num());
		}
	}
}

void UDoorComponent::GetOriginalTransform()
{
	OriginalTransform = GetOwner()->GetActorTransform();
}

void UDoorComponent::OpenDoor()
{
	FString Name = GetOwner()->GetActorNameOrLabel();
	UE_LOG(LogTemp, Display, TEXT("%s: NO Move or Rotate"), *Name);
}