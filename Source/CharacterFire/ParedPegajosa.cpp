// Fill out your copyright notice in the Description page of Project Settings.


#include "ParedPegajosa.h"

// Sets default values
AParedPegajosa::AParedPegajosa()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		MeshPegajosa(TEXT("StaticMesh'/Game/Geometry/Pared/ParedPegajosa/ParedPegajosa.ParedPegajosa'"));
	if (MeshPegajosa.Succeeded()) {
		ParedMesh->SetStaticMesh(MeshPegajosa.Object);
	}

}

// Called when the game starts or when spawned
void AParedPegajosa::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AParedPegajosa::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AParedPegajosa::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this)) {
		Mensaje();
	}
}

void AParedPegajosa::Mensaje()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green,
		FString::Printf(TEXT("Esta es una pared pegajosa")));
}

