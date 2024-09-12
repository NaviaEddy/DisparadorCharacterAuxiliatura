// Copyright Epic Games, Inc. All Rights Reserved.

#include "CharacterFireGameMode.h"
#include "CharacterFireCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACharacterFireGameMode::ACharacterFireGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
