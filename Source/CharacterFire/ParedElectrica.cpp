// Fill out your copyright notice in the Description page of Project Settings.


#include "ParedElectrica.h"

// Sets default values
AParedElectrica::AParedElectrica()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		MeshElectrica(TEXT("StaticMesh'/Game/Geometry/Pared/ParedElectrica/ParedElectrica.ParedElectrica'"));
	if (MeshElectrica.Succeeded()) {
		ParedMesh->SetStaticMesh(MeshElectrica.Object);
	}

}

// Called when the game starts or when spawned
void AParedElectrica::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AParedElectrica::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AParedElectrica::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this)) {
		Mensaje();
	}
}

void AParedElectrica::Mensaje()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Emerald,
		FString::Printf(TEXT("Esta es una pared electrica")));
}

