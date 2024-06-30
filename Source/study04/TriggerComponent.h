// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "UnlockComponent.h"
#include "TriggerComponent.generated.h"

/**
 * 
 */

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class STUDY04_API UTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTriggerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	AActor* GetAcceptableKey() const;

	/*UFUNCTION(BlueprintCallable)
	void GetInteraction();*/

	void ControlDoor();

	UFUNCTION(BlueprintCallable)
	void ControlButton();

	void SetLockState(bool State);

private:
	/* Variables */
	UPROPERTY(EditAnywhere)
	FName AcceptableActorTag;

	// Detail 패널에서 문 연결
	UPROPERTY(EditAnywhere)
	AActor* Door;

	UUnlockComponent* UnlockComponent;

	APlayerController* PlayerController;

	/* Function */
	void GetUnlockComponent();
};