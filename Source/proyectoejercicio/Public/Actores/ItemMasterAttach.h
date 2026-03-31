// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <UObject/ObjectMacros.h>

#include "Components/SphereComponent.h"
#include "ItemMasterAttach.generated.h"

class UStaticMeshComponent;


UCLASS()
class PROYECTOEJERCICIO_API AItemMasterAttach : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemMasterAttach();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "item", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* AItemMasterAttachArmas;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "item", meta = (AllowPrivateAccess = "true"))
	USphereComponent* SphereCollision;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "item", meta = (AllowPrivateAccess = "true"))
	FName SocketName = "";


};
