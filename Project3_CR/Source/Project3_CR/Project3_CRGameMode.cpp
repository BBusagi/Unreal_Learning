// Copyright Epic Games, Inc. All Rights Reserved.

#include "Project3_CRGameMode.h"
#include "Project3_CRCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProject3_CRGameMode::AProject3_CRGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
