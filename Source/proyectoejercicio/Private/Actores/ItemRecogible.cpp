#include "Actores/ItemRecogible.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "interfaz/interfazmonedas.h" 
#include <Actores/Characterprincipal.h>

// Sets default values
AItemRecogible::AItemRecogible()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereCollision = CreateDefaultSubobject <USphereComponent> (TEXT("SphereCollision"));
	RootComponent = SphereCollision;

	SphereMesh = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("SphereMesh"));
	SphereMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AItemRecogible::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemRecogible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItemRecogible::NotifyActorBeginOverlap(AActor* OtherActor)
{
	
	Super::NotifyActorBeginOverlap(OtherActor);

	if (OtherActor->Implements<Uinterfazmonedas>())
	{

		Iinterfazmonedas::Execute_AddMonedas(OtherActor,MontoMonedas);
		
	}
	
}