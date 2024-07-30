//Fill out your copyright notice in the Description page of Project Settings.


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
	TickTime = DeltaTime;

	CheckAllLocks();
}

void UDoorComponent::GetLockComponent()
{
	FString DoorName = GetOwner()->GetActorNameOrLabel();

	for (AActor* Lock : Locks)
	{
		if (!Lock) 
		{
			UE_LOG(LogTemp, Error, TEXT("%s: No Lock"), *DoorName);
			
			continue;
		}
		
		FString LockName = Lock->GetActorNameOrLabel();
		ULockComponent* LockComponent = Lock->FindComponentByClass<ULockComponent>();

		if (!LockComponent)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s: NO Lock Component"), *LockName);
		}

		else
		{
			LockComponents.Add(LockComponent);
			UE_LOG(LogTemp, Warning, TEXT("%s: LockComponents SIZE - %d "), *DoorName, LockComponents.Num());
		}
	}
}

void UDoorComponent::GetOriginalTransform()
{
	OriginalTransform = GetOwner()->GetActorTransform();
}

void UDoorComponent::CheckAllLocks()
{
	if (LockComponents.Num() == 0) return;

	for (ULockComponent* LockComponent : LockComponents)
	{
		if (!LockComponent->GetIsUnlock()) 
		{
			if (LockComponent->GetIsToggleable()) 
			{
				CloseDoor();
			}

			return;
		}
	}

	OpenDoor();
}

void UDoorComponent::OpenDoor()
{
	FString Name = GetOwner()->GetActorNameOrLabel();
	UE_LOG(LogTemp, Display, TEXT("%s: OPEN, NO Move or Rotate"), *Name);
}

void UDoorComponent::CloseDoor()
{
	FString Name = GetOwner()->GetActorNameOrLabel();
	UE_LOG(LogTemp, Display, TEXT("%s: CLOSE, NO Move or Rotate"), *Name);
}
