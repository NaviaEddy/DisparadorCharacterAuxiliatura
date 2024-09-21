// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pared.h"
#include "ParedElectrica.generated.h"

UCLASS()
class CHARACTERFIRE_API AParedElectrica : public APared
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AParedElectrica();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	void Mensaje() override;

};
