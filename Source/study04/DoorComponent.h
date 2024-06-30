// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LockComponent.h"
#include "DoorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
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

private:
	/* Variables */
	// Detail 패널에서 자물쇠 연결
	UPROPERTY(EditAnywhere)
	TArray<AActor*> Locks;

	TArray <ULockComponent*> LockComponents;

	FTransform OriginalTransform;

	/* Function */
	void GetLockComponent();
	void GetOriginalTransform();
	void OpenDoor();
};
