// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoinClassC.generated.h"

UCLASS()
class CPPGAMEA_API ACoinClassC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoinClassC();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* CoinMesh;

	UFUNCTION()
	void CoinMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Sound")
	USoundBase* CoinSound;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

