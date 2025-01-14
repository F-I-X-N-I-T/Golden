// Copyright Epic Games, Inc. All Rights Reserved.

#include "CPPGameAGameMode.h"
#include "CPPGameACharacter.h"
#include "UObject/ConstructorHelpers.h"

ACPPGameAGameMode::ACPPGameAGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
