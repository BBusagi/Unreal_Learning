// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Trigger.generated.h"

/**
 *
 */

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECT3_CR_API UTrigger : public UBoxComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
};
