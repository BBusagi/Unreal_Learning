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
	UE_LOG(LogTemp,Display,TEXT("%f"), velocityR);
	if (!reSize.IsZero()) 
	{
		SetActorScale3D(reSize);
	}
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLoc = GetActorLocation();

	CurrentLoc = CurrentLoc + velocityR * DeltaTime;
	SetActorLocation(CurrentLoc);

	float distR = FVector::Dist(startLoc,CurrentLoc);

	if(distR > movingDis)
	{
		FVector moveDir = velocityR.GetSafeNormal();
		startLoc = startLoc + moveDir * movingDis;
		SetActorLocation(startLoc);
		velocityR = -velocityR;
	}
}

