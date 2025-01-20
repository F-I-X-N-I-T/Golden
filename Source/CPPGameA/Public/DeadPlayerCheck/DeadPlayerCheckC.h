// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"
#include "GameFramework/Actor.h"
#include "DeadPlayerCheckC.generated.h"

UCLASS()
class CPPGAMEA_API ADeadPlayerCheckC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeadPlayerCheckC();

	UPROPERTY()
	class UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DeadPlayerCheck")
	TArray<ATargetPoint*> DeadPlayerCheckPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DeadPlayerCheck")
	FName PlayerTag = FName("None");

	UFUNCTION()
	void BoxDeadBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
