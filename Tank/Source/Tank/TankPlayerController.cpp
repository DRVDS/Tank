// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::Tick(float deltatime)
{
	Super::Tick(deltatime);
	AimTowardsCrosshair();
	
}


ATankCpp* ATankPlayerController::GetControlTank() const
{
	return Cast<ATankCpp>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto* PossedTank = GetControlTank();
	if(PossedTank){
		UE_LOG(LogTemp, Warning, TEXT("Possessed Tank: %s "), *PossedTank->GetName());
	}
	else{
		UE_LOG(LogTemp, Warning, TEXT("No Tank possessed"));
	}
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlTank()) { return; }
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	FVector LookDirection;

	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	
	if(GetLookDirection(ScreenLocation, LookDirection))
	{ 
		//UE_LOG(LogTemp, Warning, TEXT("Out_LookDirection : %s "), *Out_LookDirection.ToString());
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}

	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);

	FCollisionQueryParams QueryParams;
	FHitResult HitResult;

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		) 
	{
		HitLocation = HitResult.Location;
		return true;
	}
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation,FVector& Out_LookDirection) const
{
	// dont care about the cameraLoction
	FVector CameraLocation;	
	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraLocation, Out_LookDirection);

	return true;
}