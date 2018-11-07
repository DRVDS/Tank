// Fill out your copyright notice in the Description page of Project Settings.

#include "TankCpp.h"
#include "TankBarrelComponent.h"
#include "TankAimingComponent.h"

// Sets default values
ATankCpp::ATankCpp()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));

}

// Called when the game starts or when spawned
void ATankCpp::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ATankCpp::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void  ATankCpp::SetBarrelReference(UTankBarrelComponent* BarrelToSet)
{
	if (BarrelToSet) {
		TankAimingComponent->SetBarrelReference(BarrelToSet);
	}
		
}


void ATankCpp::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}
