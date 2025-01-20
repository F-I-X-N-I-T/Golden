// Fill out your copyright notice in the Description page of Project Settings.


#include "Platform/PlatformC.h"

// Sets default values
APlatformC::APlatformC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform Mesh"));
	PlatformMesh->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void APlatformC::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = GetActorLocation();
	CurrentLocation = InitialLocation;
	
}

// Called every frame
void APlatformC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentLocation = CurrentLocation + (DirectionMovement * Speed * DeltaTime);

	SetActorLocation(CurrentLocation);

	if (FVector::Dist(InitialLocation, CurrentLocation) >= MaxDistance)
	{
		DirectionMovement *= -1;
	}
}

