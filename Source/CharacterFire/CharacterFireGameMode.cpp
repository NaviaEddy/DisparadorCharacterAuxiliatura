// Copyright Epic Games, Inc. All Rights Reserved.

#include "CharacterFireGameMode.h"
#include "CharacterFireCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Pared.h"
#include "ParedCongelante.h"
#include "ParedElectrica.h"
#include "ParedPegajosa.h"

ACharacterFireGameMode::ACharacterFireGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	Paredes.Add(APared::StaticClass());
	Paredes.Add(AParedCongelante::StaticClass());
	Paredes.Add(AParedPegajosa::StaticClass());
	Paredes.Add(AParedElectrica::StaticClass());
}

void ACharacterFireGameMode::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(Timer, this, &ACharacterFireGameMode::GenerarParedesAleatorias, 3.F, true);
}

void ACharacterFireGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACharacterFireGameMode::GenerarParedesAleatorias()
{
	FVector UbicacionAleatoria = FVector(FMath::FRandRange(830.f, 1500.f), -680.f, 240.f);
	if (Paredes.Num() > 0) {
		IndiceAleatorio = FMath::FRandRange(0, Paredes.Num() - 1);
		ParedesAleatorias = Paredes[IndiceAleatorio];
		if (ParedesAleatorias) {
			GetWorld()->SpawnActor<APared>(ParedesAleatorias, UbicacionAleatoria, 
				FRotator::ZeroRotator);
		}
	}
}
