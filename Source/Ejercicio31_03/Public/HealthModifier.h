#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthModifier.generated.h"

// Evento (Delegado) 
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTickApplied, int32, TicksCount);

UCLASS()
class EJERCICIO31_03_API AHealthModifier : public AActor
{
    GENERATED_BODY()

public:
    AHealthModifier();

protected:
    virtual void BeginPlay() override;

    // colision
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    class USphereComponent* SphereComponent;

    // variables configurables
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Config")
    bool bIsHealing = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Config")
    float EffectAmount = 10.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Config")
    float TickInterval = 1.0f;

    // evento
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnTickApplied OnTickApplied;

    FTimerHandle TimerHandle_Effect;
    int32 CurrentTicks = 0;

    AActor* OverlappingActor;

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    void ApplyEffect();
};