// Fill out your copyright notice in the Description page of Project Settings.


#include "DeadPlayerCheck/DeadPlayerCheckC.h"

#include "Components/BoxComponent.h"

// Sets default values
ADeadPlayerCheckC::ADeadPlayerCheckC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ADeadPlayerCheckC::BoxDeadBeginOverlap);
	
}

void ADeadPlayerCheckC::BoxDeadBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		if (OtherActor->Tags.Contains(PlayerTag))
		{
			OtherActor->SetActorLocation(DeadPlayerCheckPoints[FMath::RandRange(0,DeadPlayerCheckPoints.Num() - 1)]->GetActorLocation());
		}
	}
}

// Called when the game starts or when spawned
void ADeadPlayerCheckC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADeadPlayerCheckC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

