// Copyright Epic Games, Inc. All Rights Reserved.

#include "C_LearnGameMode.h"
#include "C_LearnPlayerController.h"
#include "C_LearnCharacter.h"
#include "UObject/ConstructorHelpers.h"

AC_LearnGameMode::AC_LearnGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AC_LearnPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}