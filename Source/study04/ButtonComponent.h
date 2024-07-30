// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LockComponent.h"
#include "ButtonComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STUDY04_API UButtonComponent : public ULockComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UButtonComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	/* Variables */

	/* Functions */
	virtual void ControlDoor() override;

private:
	/* Variables */

	/* Functions */
	bool CheckOnInteract();

};
