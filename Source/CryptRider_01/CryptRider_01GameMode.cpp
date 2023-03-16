// Copyright Epic Games, Inc. All Rights Reserved.

#include "CryptRider_01GameMode.h"
#include "CryptRider_01Character.h"
#include "UObject/ConstructorHelpers.h"

ACryptRider_01GameMode::ACryptRider_01GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
