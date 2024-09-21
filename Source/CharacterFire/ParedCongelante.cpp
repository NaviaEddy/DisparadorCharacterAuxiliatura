// Fill out your copyright notice in the Description page of Project Settings.


#include "ParedCongelante.h"

AParedCongelante::AParedCongelante()
{
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> 
		MeshCongelante(TEXT("StaticMesh'/Game/Geometry/Pared/ParedCongelante/ParedCongelante.ParedCongelante'"));
	if (MeshCongelante.Succeeded()) {
		ParedMesh->SetStaticMesh(MeshCongelante.Object);
	}
}

void AParedCongelante::BeginPlay()
{
	Super::BeginPlay();
}

void AParedCongelante::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AParedCongelante::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this)) {
		Mensaje();
	}
}

void AParedCongelante::Mensaje()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan,
		FString::Printf(TEXT("Esta es una pared congelante")));
}
