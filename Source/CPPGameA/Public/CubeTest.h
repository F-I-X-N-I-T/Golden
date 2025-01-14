// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubeTest.generated.h"

UCLASS()
class CPPGAMEA_API ACubeTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubeTest();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cube Properties", meta = (DisplayName = "Max Health Value"))
	int32 Health = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cube Properties", meta = (DisplayName = "Damage Value"))
	int32 Damage = 25.f;
	
	UFUNCTION(BlueprintCallable)
	bool IsPlayerDead(bool bValue, int32 HealthValue, int32& HealthOut);

	UPROPERTY(BlueprintReadWrite, Category = "Cube Properties")
	bool bAlive = false;

	UFUNCTION()
	int32 IntLife(int32& HealthValue, int32& DamageValue);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
