// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"



ATankCpp* ATankAIController::GetControlTank() const
{
	return Cast<ATankCpp>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto* PlayerTank = GetPlayerTank();
	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI found Player Tank: %s "), *PlayerTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No PLayerTankFound"));
	}
}


ATankCpp* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) 
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank not found"));
		return nullptr; 
	}
	return Cast<ATankCpp>(PlayerPawn);
}