// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "BaseGeometryActor.generated.h"

UENUM(BlueprintType)
enum class EMovementType : uint8
{
	Sin,
	Static
};

USTRUCT(BlueprintType)
struct FGeometryData
{
	 GENERATED_USTRUCT_BODY()

		 UPROPERTY(EditAnywhere, Category = "Movement")
		 float Amplitude = 50.0f;

	 UPROPERTY(EditAnywhere, Category = "Movement")
		 float Freqency = 2.0f;

	 UPROPERTY(EditAnywhere, Category = "Movement")
		 EMovementType MoveType = EMovementType::Static;


};

UCLASS()
class GEOMETRYSANDBOX3_API ABaseGeometryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseGeometryActor();

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* BaseMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere, Category = "GeometryData")
	FGeometryData GeometryData;

	UPROPERTY(EditAnywhere, Category= "Weapon")
	int32 WeaponNum = 4;

	UPROPERTY(EditDefaultsOnly, Category = "Stat")
	int32 KillsNum = 7;

	UPROPERTY(EditInstanceOnly, Category = "Health")
	float Health = 34.43f;

	UPROPERTY(EditAnywhere, Category = "Health")
	bool IsDead = false;

	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	bool HasWeapon = true;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	void HandleMovement();
	void PrintTransform();
	FVector InitialLocation;
	void PrintTypes();
	void PrintStringTypes();
};
