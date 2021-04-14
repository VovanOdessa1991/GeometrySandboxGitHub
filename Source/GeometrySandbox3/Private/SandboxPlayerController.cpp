// Fill out your copyright notice in the Description page of Project Settings.


#include "SandboxPlayerController.h"
#include "Components/InputComponent.h"

#include "Kismet/GameplayStatics.h"
#include "SandBoxPawn.h"

DEFINE_LOG_CATEGORY_STATIC(LogSandboxPlayerController, All, All)
void ASandboxPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if (InputComponent)
	{
		InputComponent->BindAction("ChangePawn", IE_Pressed, this, &ASandboxPlayerController::ChangePawn);
	}
}

void ASandboxPlayerController::BeginPlay()
{

	Super::BeginPlay();
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASandBoxPawn::StaticClass(), Pawns);
}

void ASandboxPlayerController::ChangePawn()
{
	if (Pawns.Num() <= 1) return;
	ASandBoxPawn* CurrentPawn = Cast<ASandBoxPawn>(Pawns[CurrentPawnIndex]); \

		CurrentPawnIndex = (CurrentPawnIndex + 1) % Pawns.Num();
	if (!CurrentPawn) return;

	UE_LOG(LogSandboxPlayerController, Error, TEXT("CAnge player pawn ")); 

	Possess(CurrentPawn);
}
