// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrelComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANK_API UTankBarrelComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void SetElevate(float Degrees);

private:
	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 5;

	UPROPERTY(EditAnywhere)
	float MinElevationinDegrees = 0;

	UPROPERTY(EditAnywhere)
	float MaxElevationinDegrees = 40;
};
