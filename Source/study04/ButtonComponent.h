#pragma once

#include "CoreMinimal.h"
#include "TriggerComponent.h"
#include "ButtonComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class STUDY04_API UButtonComponent : public UTriggerComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UButtonComponent();

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:
    // Override ControlDoor function
    UFUNCTION(BlueprintCallable)
    virtual void ControlDoor() override;
};
