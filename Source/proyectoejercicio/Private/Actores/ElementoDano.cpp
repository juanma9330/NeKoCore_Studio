// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "InterfazDano.generated.h"
#include "ComponenteSalud.generated.h"
#include "Actores/ElementoDano.h"

// Sets default values
AElementoDano::AElementoDano()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SphereCollision = CreateDefaultSubobject <USphereComponent>(TEXT("SphereCollision"));
	RootComponent = SphereCollision;

	SphereMesh = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("SphereMesh"));
	SphereMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AElementoDano::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AElementoDano::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AElementoDano::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (OtherActor->Implements<UInterfazDano>());
	{
		IInterfazDano
	}
}

