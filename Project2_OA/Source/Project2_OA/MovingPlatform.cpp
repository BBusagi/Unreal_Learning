// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	startLoc = GetActorLocation();

	velocityR = movingVelo * 100 * movingVect;
	if (!reSize.IsZero())
	{
		SetActorScale3D(reSize);
	}
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlateform(DeltaTime);
	RotatePlateform(DeltaTime);
}

void AMovingPlatform::MovePlateform(float DeltaTime)
{
	if (shouldReturn())
	{
		// float overShoot = distR - movingDis;
		// FString name = GetName();
		// UE_LOG(LogTemp, Display, TEXT("%s overShoot: %f"), *name, overShoot);

		FVector moveDir = velocityR.GetSafeNormal();
		startLoc = startLoc + moveDir * movingDis;
		SetActorLocation(startLoc);
		velocityR = -velocityR;
	}
	else
	{
		FVector CurrentLoc = GetActorLocation();
		CurrentLoc = CurrentLoc + velocityR * DeltaTime;
		SetActorLocation(CurrentLoc);
	}
}

void AMovingPlatform::RotatePlateform(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("%s rotating..."), *GetName());
}

bool AMovingPlatform::shouldReturn() const
{
	return getDistMoved() > movingDis;
}

float AMovingPlatform::getDistMoved() const
{
	return FVector::Dist(startLoc, GetActorLocation());
}