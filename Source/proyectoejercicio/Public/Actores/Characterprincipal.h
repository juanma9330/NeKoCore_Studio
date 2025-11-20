// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "interfaz/interfazmonedas.h"
#include "interfaz/interfazparahacerdanio.h"
#include "InputActionValue.h"
#include "Characterprincipal.generated.h"


class UInputAction;
class UInputMappingContext;
UCLASS(Abstract)
class PROYECTOEJERCICIO_API ACharacterprincipal : public ACharacter, public Iinterfazmonedas , public Iinterfazparahacerdanio
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterprincipal();
	
	virtual void AddMonedas_Implementation(int Moneda) override;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventario")
	int Monedas =0;

	
	UFUNCTION(BlueprintCallable)
	void MostrarMensaje();
 
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// ---- Enhanced Input ----
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* IMC_Player;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* IA_Movimiento;

	void Move(const FInputActionValue& Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
