// Fill out your copyright notice in the Description page of Project Settings.

#include "Actores/Characterprincipal.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"

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

	// ?? AGREGAR ESTE LOG AQUÍ
	UE_LOG(LogTemp, Warning, TEXT("InputComponent usado: %s"),
		*PlayerInputComponent->GetClass()->GetName());

	// Ahora sí, tu cast normal
	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInput->BindAction(IA_Movimiento, ETriggerEvent::Triggered, this, &ACharacterprincipal::Move);
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

		UE_LOG(LogTemp, Warning, TEXT("MOV: X=%f Y=%f"), InputVec.X, InputVec.Y);

	}
}

void ACharacterprincipal::MostrarMensaje()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Overlapeando"));

		
	}
}

