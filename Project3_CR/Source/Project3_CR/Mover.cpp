// Fill out your copyright notice in the Description page of Project Settings.

#include "Mover.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	OriginLoc = GetOwner()->GetActorLocation();
}

// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (ShouldMove)
	{
		FVector CurrentLoc = GetOwner()->GetActorLocation();
		FVector TargetLoc = OriginLoc + MoveOffset;

		float Speed = FVector::Distance(OriginLoc, TargetLoc) / MoveTime;
		FVector NewLoc = FMath::VInterpConstantTo(CurrentLoc, TargetLoc, DeltaTime, Speed);
		GetOwner()->SetActorLocation(NewLoc);
		
		UE_LOG(LogTemp, Display, TEXT("Moving"));
	}



	// ...
}
