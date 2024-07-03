// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LockComponent.h"
#include "DoorComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class STUDY04_API UDoorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UDoorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	/* Variables */
	UPROPERTY(EditAnywhere)
	FTransform Offset;
	UPROPERTY(EditAnywhere)
	float Time = 4;
	FTransform OriginalTransform;
	float TickTime;

	/* Function */
	virtual void OpenDoor();

private:
	/* Variables */
	UPROPERTY(EditAnywhere)
	TArray<AActor*> Locks; // Detail 패널에서 자물쇠 연결
	TArray <ULockComponent*> LockComponents;

	/* Functions */
	void GetLockComponent();
	void GetOriginalTransform();
	void CheckAllLocks();
};
