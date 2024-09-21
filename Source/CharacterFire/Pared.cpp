// Fill out your copyright notice in the Description page of Project Settings.

#include "Pared.h"
#include "Components/BoxComponent.h"

// Sets default values
APared::APared()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		Mesh(TEXT("StaticMesh'/Game/Geometry/Pared/ParedNormal/ParedNormal.ParedNormal'"));

	ParedMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pared_mesh"));
	if (Mesh.Succeeded()) {
		ParedMesh->SetStaticMesh(Mesh.Object);
	}
	ParedMesh->SetRelativeScale3D(FVector(1.25f, 0.25f, 1.75f));
	RootComponent = ParedMesh;

	ParedCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Pared_collision"));
	ParedCollision->SetVisibility(true);
	ParedCollision->SetRelativeScale3D(FVector(2.f, 4.f, 1.60f));
	ParedCollision->SetCollisionProfileName(TEXT("Triger"));
	ParedCollision->SetupAttachment(GetRootComponent());

	ParedCollision->OnComponentBeginOverlap.AddDynamic(this, &APared::OnOverlapBegin);

	InitialLifeSpan = 2.f;
}

// Called when the game starts or when spawned
void APared::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APared::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APared::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this)) {
		Mensaje();
	}
}

void APared::Mensaje()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, 
		FString::Printf(TEXT("Esta es una pared normal")));
}

