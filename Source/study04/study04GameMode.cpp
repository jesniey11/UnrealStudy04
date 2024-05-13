// Copyright Epic Games, Inc. All Rights Reserved.

#include "study04GameMode.h"
#include "study04Character.h"
#include "UObject/ConstructorHelpers.h"

Astudy04GameMode::Astudy04GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
