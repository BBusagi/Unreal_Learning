// Fill out your copyright notice in the Description page of Project Settings.

#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
    PrimaryComponentTick.bCanEverTick = true;

    UE_LOG(LogTemp, Display, TEXT("TriggerComponent Constructing"));
}

void UTriggerComponent::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Display, TEXT("TriggerComponent Component Alive"));
}

void UTriggerComponent::SetMover(UMover* NewMover)
{
    Mover = NewMover;
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    AActor *Actor = GetAcceptableActor();
    if (Actor != nullptr)
    {
        UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
        if(Component != nullptr)
        {
            Component->SetSimulatePhysics(false);
        }

        Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);

        Mover->SetShouldMove(true);
    }
    else
    {
        Mover->SetShouldMove(false);
    }
}

AActor *UTriggerComponent::GetAcceptableActor() const
{
    TArray<AActor *> Actors;
    GetOverlappingActors(Actors);

    for (AActor *Actor : Actors)
    {
        bool HasAcceptableActorTag = Actor->ActorHasTag(AcceptableActorTag);
        bool IsGrabbed = Actor->ActorHasTag("Grabbed");

        if (HasAcceptableActorTag && !IsGrabbed)
        {
            return Actor;
        }
    }

    return nullptr;
}