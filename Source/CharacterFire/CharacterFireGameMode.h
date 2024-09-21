// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CharacterFireGameMode.generated.h"

UCLASS(minimalapi)
class ACharacterFireGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACharacterFireGameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	TArray<TSubclassOf<class APared>> Paredes;

	FTimerHandle Timer;

	void GenerarParedesAleatorias();

	int32 IndiceAleatorio;

	TSubclassOf<class APared> ParedesAleatorias;
};



