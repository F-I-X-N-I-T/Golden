// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GM_Coins.generated.h"

/**
 * 
 */
UCLASS()
class CPPGAMEA_API AGM_Coins : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGM_Coins();
	//BeginPlay all
	virtual void BeginPlay() override;

	FTimerHandle TimerHandleDown;

	void CountDownTickStop();

	UFUNCTION(BlueprintCallable)
	void CallTimerUpdate();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coin Properties")
	int32 TimeRemaining = 10.f;

	//Logic coin

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CoinsNeededCPP = 5;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CoinsGhateredCPP = 0;

	UFUNCTION()
	void CoinCounterCPP();

	UFUNCTION()
	void WinningConditionCheck();

	// End Logic coin

	// Logic Sound
	
	UFUNCTION(BlueprintCallable)
	void FadeOutMusic(float FadeOutDuration);
	
	// End Logic Sound
protected:

	// Logic Sound
	
	UPROPERTY(EditAnywhere, Category = "Sound")
	USoundBase* MusicSound;

	UPROPERTY()
	UAudioComponent* MusicAudioComponent;

	UPROPERTY(EditAnywhere, Category = "Sound")
	float FadeOutTime = 0.4f;
	
	// End Logic Sound

	//Tick all
	virtual void Tick(float DeltaSeconds) override;
	
};
