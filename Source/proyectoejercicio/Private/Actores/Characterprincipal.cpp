// Fill out your copyright notice in the Description page of Project Settings.

#include "Actores/Characterprincipal.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"

ACharacterprincipal::ACharacterprincipal()
{
	PrimaryActorTick.bCanEverTick = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);
}

void ACharacterprincipal::AddMonedas_Implementation(int Moneda)
{
	Monedas += Moneda;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::FromInt(Monedas));
	}
}

void ACharacterprincipal::BeginPlay()
{
	Super::BeginPlay();
}

void ACharacterprincipal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACharacterprincipal::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (IA_Movimiento)
		{
			EnhancedInput->BindAction(IA_Movimiento, ETriggerEvent::Triggered, this, &ACharacterprincipal::Move);
		}
	}
}

void ACharacterprincipal::Move(const FInputActionValue& Value)
{
	const FVector2D InputVec = Value.Get<FVector2D>();

	if (Controller)
	{
		
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

		const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(Forward, InputVec.Y);
		AddMovementInput(Right, InputVec.X);
	}
}

void ACharacterprincipal::MostrarMensaje()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Overlapeando"));
	}
}
