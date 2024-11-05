#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Paddle.generated.h"

UCLASS()
class BJBREAKOUT_API APaddle : public AActor
{
	GENERATED_BODY()

public:
	// Constructor
	APaddle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Function to move the paddle
	void MovePaddle(float AxisValue);

protected:
	// Paddle mesh
	UPROPERTY(EditAnywhere, Category="Paddle")
	UStaticMeshComponent* PaddleMesh;

	// Movement speed for the paddle
	UPROPERTY(EditAnywhere, Category="Movement")
	float MovementSpeed;
};
