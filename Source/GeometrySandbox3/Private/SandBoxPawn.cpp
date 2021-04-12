// Fill out your copyright notice in the Description page of Project Settings.


#include "SandBoxPawn.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"


DEFINE_LOG_CATEGORY_STATIC(LogSandboxPawn, All, All)

// Sets default values
ASandBoxPawn::ASandBoxPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

}

// Called when the game starts or when spawned
void ASandBoxPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASandBoxPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!VelocityVector.IsZero()) 
	{
		FVector NewLocation = GetActorLocation()+Velocity*DeltaTime*VelocityVector;
		SetActorLocation(NewLocation);
	}

}

// Called to bind functionality to input
void ASandBoxPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Управление Инпутами
	PlayerInputComponent->BindAxis("MoveForward", this, &ASandBoxPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASandBoxPawn::MoveRight);

}

void ASandBoxPawn::MoveForward(float Amount)
{
	UE_LOG(LogSandboxPawn, Display, TEXT("Move forward: %f"), Amount);
	VelocityVector.X = Amount;
}

void ASandBoxPawn::MoveRight(float Amount)
{
	UE_LOG(LogSandboxPawn, Display, TEXT("Move Right: %f"), Amount);
	VelocityVector.Y = Amount;
}

