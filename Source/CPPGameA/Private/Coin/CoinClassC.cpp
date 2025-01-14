// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin/CoinClassC.h"

// Sets default values
ACoinClassC::ACoinClassC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CoinMesh"));
	RootComponent = CoinMesh;

}

// Called when the game starts or when spawned
void ACoinClassC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoinClassC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

