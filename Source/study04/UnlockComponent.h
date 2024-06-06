// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UnlockComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STUDY04_API UUnlockComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUnlockComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/* Variables */
	// 한번 열린 문이 다시 닫힐 수 있으면 true
	UPROPERTY(EditAnywhere)
	bool IsToggleable = false;

	/* Function */
	bool GetIsUnlock() const;
	void SetIsUnlock(bool IsUnlock);

private:
	/* Variables */
	UPROPERTY(VisibleAnywhere)
	bool IsUnlock = false;
};
