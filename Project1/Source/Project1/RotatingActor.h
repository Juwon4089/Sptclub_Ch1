#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor.generated.h"

UCLASS()
class PROJECT1_API ARotatingActor : public AActor
{
	GENERATED_BODY()

public:
	ARotatingActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rotating")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotating", meta = (ToolTip = "초당 회전량 (Pitch, Yaw, Roll)"))
	FRotator RotationSpeed;
};
