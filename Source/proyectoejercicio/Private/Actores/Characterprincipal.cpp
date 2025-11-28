#include "Actores/Characterprincipal.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h" 
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"

// Constructor
ACharacterprincipal::ACharacterprincipal()
{
    PrimaryActorTick.bCanEverTick = true;

    // 1. Configuración de rotación
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;

    // 2. Configuración del Movimiento
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f);
    GetCharacterMovement()->bUseControllerDesiredRotation = false;
}

// BeginPlay
void ACharacterprincipal::BeginPlay()
{
    Super::BeginPlay();
}

// Tick (Esta es la que te daba error LNK2001 por faltar)
void ACharacterprincipal::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// SetupPlayerInputComponent
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

// Lógica de Movimiento Corregida
void ACharacterprincipal::Move(const FInputActionValue& Value)
{
    const FVector2D InputVec = Value.Get<FVector2D>();

    if (!Controller) return;

    // --- EJE X (A y D): Rota la CÁMARA ---
    if (InputVec.X != 0.0f)
    {
        AddControllerYawInput(InputVec.X);
    }

    // --- EJE Y (W y S): Mueve al PERSONAJE ---
    if (InputVec.Y != 0.0f)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);
        const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

        AddMovementInput(ForwardDirection, InputVec.Y);
    }
}

// Interfaz Monedas (Esta faltaba y daba error LNK2001)
void ACharacterprincipal::AddMonedas_Implementation(int Moneda)
{
    Monedas += Moneda;

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Monedas: %d"), Monedas));
    }
}

// Función Mostrar Mensaje (Esta faltaba y daba error LNK2019)
void ACharacterprincipal::MostrarMensaje()
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Overlapeando"));
    }
}