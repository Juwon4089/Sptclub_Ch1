#include "MovingPlatformActor.h"

AMovingPlatformActor::AMovingPlatformActor()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	MoveSpeed = 100.f;
	MaxRange = 300.f;
	MoveDirection = FVector(1.f, 0.f, 0.f);

	CurrentOffset = 0.f;
	bMovingForward = true;
}

void AMovingPlatformActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

void AMovingPlatformActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float MoveDelta = MoveSpeed * DeltaTime;

	if (bMovingForward)
	{
		CurrentOffset += MoveDelta;
		if (CurrentOffset >= MaxRange)
		{
			CurrentOffset = MaxRange;
			bMovingForward = false;
		}
	}
	else
	{
		CurrentOffset -= MoveDelta;
		if (CurrentOffset <= 0.f)
		{
			CurrentOffset = 0.f;
			bMovingForward = true;
		}
	}

	const FVector NewLocation = StartLocation + MoveDirection.GetSafeNormal() * CurrentOffset;
	SetActorLocation(NewLocation);
}
