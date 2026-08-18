#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatformActor.generated.h"

UCLASS()
class PROJECT1_API AMovingPlatformActor : public AActor
{
	GENERATED_BODY()

public:
	AMovingPlatformActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MovingPlatform")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatform", meta = (ClampMin = "0.0", ToolTip = "초당 이동 거리"))
	float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatform", meta = (ClampMin = "0.0", ToolTip = "시작 위치 기준 왕복 이동 범위"))
	float MaxRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatform", meta = (ToolTip = "이동 방향 벡터 (자동으로 정규화됨)"))
	FVector MoveDirection;

private:
	FVector StartLocation;
	float CurrentOffset;
	bool bMovingForward;
};
