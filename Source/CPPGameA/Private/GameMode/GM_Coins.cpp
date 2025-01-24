// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/GM_Coins.h"

#include "Coin/CoinClassC.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"

AGM_Coins::AGM_Coins()
{
	PrimaryActorTick.bCanEverTick = true;

	MusicAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));
}

void AGM_Coins::BeginPlay()
{
	Super::BeginPlay();

	//This function gets the class of the main actor and then looks for the subclass to find the array I need.
	GetAllCoinsInWorld(ACoinClassC::StaticClass());

	//Timer
	GetWorldTimerManager().SetTimer(TimerHandleDown, this, &AGM_Coins::CountDownTickStop, 1.f, true);
	
	//We use it to “Set” the variable, we can use it here in c++ or in bp for something
	//I put it as BlueprintCallable, but it looks ugly in bp xd
	CallTimerUpdate();

	//Music
	if (MusicSound)
	{
		MusicAudioComponent->SetSound(MusicSound);
		MusicAudioComponent->Play();
	}
	
}

void AGM_Coins::CountDownTickStop()
{
	if (TimeRemaining > 0)
	{
		TimeRemaining--;
		CallTimerUpdate();
	}
	else
	{
		GetWorldTimerManager().ClearTimer(TimerHandleDown);
	}
}

void AGM_Coins::CallTimerUpdate()
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

		WinningConditionCheck();
	}
}

void AGM_Coins::WinningConditionCheck()
{
	if (CoinsGhateredCPP == CoinsNeededCPP)
	{
		UWorld* World = GetWorld();
		
		if (World)
		{
			AGameModeBase* GameMode = UGameplayStatics::GetGameMode(World);
			FadeOutMusic(FadeOutTime);

			if (GameMode)
			{
				UFunction* BPFunctionWin = GameMode->FindFunction(FName("WinningCondition"));
				UFunction* BPFunctionWinMessage = GameMode->FindFunction(FName("ShowMessageWinHud"));

				if (BPFunctionWin && BPFunctionWinMessage)
				{
					GameMode->ProcessEvent(BPFunctionWin, nullptr);

					GameMode->ProcessEvent(BPFunctionWinMessage, nullptr);

					//Disable Input Player
					APlayerController* PlayerController = World->GetFirstPlayerController();
					if (PlayerController)
					{
						APawn* Player = PlayerController->GetPawn();
						if (Player)
						{
							DisablePlayerInput(Player);
						}
					}
				}
			}
		}
	}
	else
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You need more coins!"));
		}
	}
}

void AGM_Coins::FadeOutMusic(float FadeOutDuration)
{
	if (MusicAudioComponent)
	{
		MusicAudioComponent->FadeOut(FadeOutDuration, 0.f);
	}
}

void AGM_Coins::GetAllCoinsInWorld(TSubclassOf<AActor> ActorClass)
{
	TArray<AActor*> FoundCoins;
	
	UWorld* World = GetWorld();
	
	if (World)
	{
		UGameplayStatics::GetAllActorsOfClass(World, ActorClass, FoundCoins);
		
		CoinsFound = FoundCoins.Num();
	}
}

void AGM_Coins::DisablePlayerInput(APawn* Player)
{
	if (Player)
	{
		APlayerController* PlayerController = Cast<APlayerController>(Player->GetController());

		if (PlayerController)
		{
			Player->DisableInput(PlayerController);
		}
	}
}

void AGM_Coins::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
}
