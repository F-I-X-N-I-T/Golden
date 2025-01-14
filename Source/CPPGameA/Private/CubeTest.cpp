// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeTest.h"

// Sets default values
ACubeTest::ACubeTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

bool ACubeTest::IsPlayerDead(bool bValue, int32 HealthValue, int32& HealthOut)
{
	if (HealthValue <= 0.f)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,
				FString::Printf(TEXT("The Boliviano is dead: %d"), Health));
		}
		bValue = true;
	}
	else if (HealthValue <= 15.f)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow,
				FString::Printf(TEXT("Cuidado mk que te mueres por jotito: %d"), Health));
		}
		bValue = false;
	}
	else
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green,
				FString::Printf(TEXT("El mk aun vive: %d"), Health));
		}
		bValue = false;
	}
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple,
				FString::Printf(TEXT("Is: %s"), bValue ? TEXT("Dead") : TEXT("Alive")));
	}
	
	HealthOut = Health;
	return bValue;
}

int32 ACubeTest::IntLife(int32& HealthValue, int32& DamageValue)
{
	HealthValue = HealthValue - DamageValue;
	return HealthValue;
}

// Called when the game starts or when spawned
void ACubeTest::BeginPlay()
{
	Super::BeginPlay();
	
	IntLife(Health, Damage);
	
	//IsPlayerDead(bAlive, Health);
}

// Called every frame
void ACubeTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

