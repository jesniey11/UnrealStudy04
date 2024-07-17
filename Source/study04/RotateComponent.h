// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DoorComponent.h"
#include "RotateComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STUDY04_API URotateComponent : public UDoorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URotateComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	/* Functions */
	virtual void OpenDoor() override;
	virtual void CloseDoor() override;

private:
	/* Variables */
	FRotator OriginalRotation;
	FRotator RotateOffset;

	/* Functions */
	FRotator SetTargetRotation();
	void RotatorTranslator();
};
