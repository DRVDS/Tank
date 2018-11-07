// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UStaticMeshComponent;
class UTankBarrelComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UTankAimingComponent();

	void AimAt(FVector HitLocation, float LaunchSpeed);

	void SetBarrelReference(UTankBarrelComponent* Barrel);

	void MoveBarrelTowards(FVector AimDirection);

	void SetTurretReference(UStaticMeshComponent* Turrent);

private:
	UTankBarrelComponent* Barrel = nullptr;
	UStaticMeshComponent* Turrent = nullptr;

};
