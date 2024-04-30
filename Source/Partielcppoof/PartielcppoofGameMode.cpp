// Copyright Epic Games, Inc. All Rights Reserved.

#include "PartielcppoofGameMode.h"
#include "PartielcppoofCharacter.h"
#include "UObject/ConstructorHelpers.h"

APartielcppoofGameMode::APartielcppoofGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
