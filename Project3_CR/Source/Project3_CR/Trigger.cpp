// Fill out your copyright notice in the Description page of Project Settings.

#include "Trigger.h"

UTrigger::UTrigger()
{
    PrimaryComponentTick.bCanEverTick = true;

    UE_LOG(LogTemp, Display, TEXT("Trigger Constructing"));
}

void UTrigger::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Display, TEXT("Trigger Component Alive"));
}

void UTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    AActor* Actor = GetAcceptableActor();
    if(Actor != nullptr)
    {
        UE_LOG(LogTemp, Display, TEXT("Unlocking"));
    }
    else
    {
        UE_LOG(LogTemp, Display, TEXT("Relocking"));
    }

}

AActor *UTrigger::GetAcceptableActor() const
{
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);

    for (AActor *Actor : Actors)
    {
        if (Actor->ActorHasTag(AcceptableActorTag))
        {
            return Actor;
        }
    }
    return nullptr;
}