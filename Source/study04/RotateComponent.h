// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RotateComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STUDY04_API URotateComponent : public UActorComponent
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

	void SetShouldRotate(bool ShouldRotate);

private:
	/* Rotate Variables */
	UPROPERTY(EditAnywhere)
	FRotator RotateOffset;

	UPROPERTY(EditAnywhere)
	float RotateTime = 4;

	UPROPERTY(EditAnywhere)
	bool ShouldRotate = false;
 
	 FVector OriginalRotation;

};
