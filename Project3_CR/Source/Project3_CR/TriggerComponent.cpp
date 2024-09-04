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

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);

    // Method 1
    // int32 index = 0;
    // while (index < Actors.Num())
    // {
    //     FString ActorName = Actors[index]->GetActorNameOrLabel();
    //     UE_LOG(LogTemp, Display, TEXT("Overlapping: %s"), *ActorName);
    //     ++index;
    // }
    
    //Method 2
    // for (int i = 0; i < Actors.Num(); i++)
    // {
    //     FString ActorName = Actors[i]->GetActorNameOrLabel();
    //     UE_LOG(LogTemp, Display, TEXT("Overlapping: %s"), *ActorName);
    // }
    
    for(AActor* Actor : Actors)
    {
        FString ActorName = Actor->GetActorNameOrLabel();
        UE_LOG(LogTemp, Display, TEXT("Overlapping: %s"), *ActorName);
    }
}