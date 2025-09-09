// Fill out your copyright notice in the Description page of Project Settings.


#include "componentes/ComponenteSalud.h"

// Sets default values for this component's properties
UComponenteSalud::UComponenteSalud()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}




// Called when the game starts
void UComponenteSalud::BeginPlay()
{
	Super::BeginPlay();
	//SaludIni();
	//AplicarDano();
	// ...
	
}


// Called every frame
void UComponenteSalud::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

