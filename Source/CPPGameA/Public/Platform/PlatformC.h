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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* PlatformMesh;

	UPROPERTY()
	FVector InitialLocation;

	UPROPERTY()
	FVector CurrentLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Properties")
	FVector DirectionMovement = FVector(0.f, 0.f, 0.f);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Properties")
	float Speed = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Properties")
	float MaxDistance = 200.f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
