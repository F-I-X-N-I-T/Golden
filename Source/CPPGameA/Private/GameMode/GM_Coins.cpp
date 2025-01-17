// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/GM_Coins.h"

#include "Kismet/GameplayStatics.h"

AGM_Coins::AGM_Coins()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGM_Coins::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(TimerHandleDown, this, &AGM_Coins::CountDownTickStop, 1.f, true);
	
	//We use it to “Set” the variable, we can use it here in c++ or in bp for something
	//I put it as BlueprintCallable but it looks ugly in bp xd
	CallTimerUpdater();
}

void AGM_Coins::CountDownTickStop()
{
	if (TimeRemaining > 0)
	{
		TimeRemaining--;
		CallTimerUpdater();
	}
	else
	{
		GetWorldTimerManager().ClearTimer(TimerHandleDown);
	}
}

void AGM_Coins::CallTimerUpdater()
{
	UWorld* World = GetWorld();
	if (World)
	{
		// Get the GameMode Actually
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(World);

		if (GameMode)
		{
			//We call the function we created in the blueprint
			UFunction* BPFunction = GameMode->FindFunction(FName("TimerUpdate"));

			if (BPFunction)
			{
				//We activate the function that we passed in the first parameter
				GameMode->ProcessEvent(BPFunction, nullptr);
			}
		}
	}
}

void AGM_Coins::CoinCounterCPP()
{
	CoinsGhateredCPP++;

	UWorld* World = GetWorld();
	if (World)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(World);

		if (GameMode)
		{
			UFunction* BPFunction = GameMode->FindFunction(FName("CoinsGhateredUpdate"));

			if (BPFunction)
			{
				GameMode->ProcessEvent(BPFunction, nullptr);
			}
		}
	}
}

void AGM_Coins::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
}
