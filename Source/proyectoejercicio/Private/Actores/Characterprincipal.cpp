// Fill out your copyright notice in the Description page of Project Settings.


#include "Actores/Characterprincipal.h"

// Sets default values
ACharacterprincipal::ACharacterprincipal()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ACharacterprincipal::AddMonedas_Implementation(int Moneda)
{
	Monedas += Moneda;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::FromInt(Monedas));
	}
}

// Called when the game starts or when spawned
void ACharacterprincipal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterprincipal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterprincipal::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACharacterprincipal::MostrarMensaje()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Overlapeando"));

		
	}
}

