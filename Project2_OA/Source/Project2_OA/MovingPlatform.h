// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class PROJECT2_OA_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingPlatform();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Moving")
	FVector velocityR = FVector(100, 0, 0);

	UPROPERTY(EditAnywhere, Category = "Moving")
	float move = 100; 

	UPROPERTY(EditAnywhere, Category = "Moving")
	FVector reSize = FVector(2, 2, 0.1);

	FVector startLoc;
};
