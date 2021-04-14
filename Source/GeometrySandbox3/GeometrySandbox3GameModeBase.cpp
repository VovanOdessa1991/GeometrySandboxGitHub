// Copyright Epic Games, Inc. All Rights Reserved.


#include "GeometrySandbox3GameModeBase.h"
#include "SandBoxPawn.h"
#include "SandboxPlayerController.h"

AGeometrySandbox3GameModeBase::AGeometrySandbox3GameModeBase()
{
	DefaultPawnClass = ASandBoxPawn::StaticClass();
	PlayerControllerClass = ASandboxPlayerController::StaticClass();
}

 