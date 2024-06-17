// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "GameFramework/InputSettings.h" 

#include "GrabComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STUDY04_API UGrabComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void Grab();

	UFUNCTION(BlueprintCallable)
	void Release();

	UFUNCTION(BlueprintCallable)
	void Interact();

private:
	UPROPERTY(EditAnywhere)
	float MaxGrabDistance = 400;

	UPROPERTY(EditAnywhere)
	float HoldDistance = 100;

	UPROPERTY(EditAnywhere)
	float GrabRadius = 100;
	
	UPhysicsHandleComponent* GetPhysicsHandle() const;
	bool GetGrabbableInReach(FHitResult& OutHitResult) const;

	/*
	void PrintDamage(const float& Damage);
	bool HasDamage(float& OutDamage);
	*/
};
