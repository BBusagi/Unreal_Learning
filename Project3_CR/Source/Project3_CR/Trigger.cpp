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

void UTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    UE_LOG(LogTemp, Display, TEXT("Trigger Component is Ticking"));

}