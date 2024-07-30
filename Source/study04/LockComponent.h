// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "LockComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class STUDY04_API ULockComponent : public UBoxComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ULockComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	/* Variables */
	UPROPERTY(EditAnywhere)
	FName AcceptableActorTag; //자물쇠와 일치하는 KEY

	UPROPERTY(EditAnywhere)
	bool IsToggleable = false; //true면 다시 잠길 수 있음

	UPROPERTY(EditAnywhere)
	bool CanDestroyKey = false;

	/* Functions */
	AActor* GetAcceptableKey() const;
	void DestroyKey(AActor* Key);

public:
	/* Variables */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsUnlock = false;

	/* Functions */
	bool GetIsUnlock() const;
	void SetIsUnlock(bool IsUnlock);

	bool GetIsToggleable() const;

	virtual void ControlDoor();
};
