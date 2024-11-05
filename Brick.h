#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Brick.generated.h"

UCLASS()
class BJBREAKOUT_API ABrick : public AActor
{
	GENERATED_BODY()

public:
	// Constructor
	ABrick();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	// Brick mesh
	UPROPERTY(EditAnywhere, Category="Brick")
	UStaticMeshComponent* BrickMesh;
};
