// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin/CoinClassC.h"

#include "Components/AudioComponent.h"
#include "GameMode/GM_Coins.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACoinClassC::ACoinClassC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CoinMesh"));
	CoinMesh->SetupAttachment(GetRootComponent());

	CoinMesh->SetWorldRotation(FRotator(90.f, 0.f, 0.f));
	CoinMesh->SetWorldScale3D(FVector(0.5f, 0.5f, 0.05f));

	CoinMesh->OnComponentBeginOverlap.AddDynamic(this, &ACoinClassC::CoinMeshBeginOverlap);

}

void ACoinClassC::CoinMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			AGameModeBase* GameModeRef = UGameplayStatics::GetGameMode(World);
		
			if (GameModeRef)
			{
				AGM_Coins* GameModeCast = Cast<AGM_Coins>(GameModeRef);
			
				if (GameModeCast)
				{
					GameModeCast->CoinCounterCPP();

					if (CoinSound)
					{
						UGameplayStatics::PlaySound2D(GetWorld(), CoinSound);
					}
				}
			}
		}
		Destroy();
	}
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

