// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformC.generated.h"

UCLASS()
class CPPGAMEA_API APlatformC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* PlatformMesh;

	//FVector GetActorLocation = GetOwner()->GetActorLocation();

	//DirectionMovement

	//CurrentLocation

	//Speed

	//MaxDistance

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
