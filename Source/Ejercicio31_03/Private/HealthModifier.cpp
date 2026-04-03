#include "HealthModifier.h"
#include "Components/SphereComponent.h"
#include "TimerManager.h"
#include "Engine/Engine.h" 

AHealthModifier::AHealthModifier()
{
    PrimaryActorTick.bCanEverTick = false;

    // esfera colssion
    SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
    RootComponent = SphereComponent;

    SphereComponent->InitSphereRadius(200.0f);

    // suscribiendo ufnciones
    SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AHealthModifier::OnOverlapBegin);
    SphereComponent->OnComponentEndOverlap.AddDynamic(this, &AHealthModifier::OnOverlapEnd);
}

void AHealthModifier::BeginPlay()
{
    Super::BeginPlay();
}

void AHealthModifier::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor != this)
    {
        OverlappingActor = OtherActor;

        GetWorldTimerManager().SetTimer(TimerHandle_Effect, this, &AHealthModifier::ApplyEffect, TickInterval, true, 0.0f);
    }
}

void AHealthModifier::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (OtherActor == OverlappingActor)
    {
        OverlappingActor = nullptr;
        GetWorldTimerManager().ClearTimer(TimerHandle_Effect);
    }
}

void AHealthModifier::ApplyEffect()
{
    if (OverlappingActor)
    {
        float AmountToApply;

        if (bIsHealing == true)
        {
            AmountToApply = EffectAmount;
        }
        else
        {
            AmountToApply = -EffectAmount;
        }

        CurrentTicks++;

        
        OnTickApplied.Broadcast(CurrentTicks);

        if (GEngine)
        {
            FString Tipo = bIsHealing ? TEXT("Curacion") : TEXT("Danio");
            GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf(TEXT("%s aplicada. Ticks totales: %d"), *Tipo, CurrentTicks));
        }
    }
}