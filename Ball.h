#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Ball.generated.h"

UCLASS()
class BJBREAKOUT_API ABall : public AActor
{
	GENERATED_BODY()

public:
	// Constructor
	ABall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Function to handle when the ball hits something
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

protected:
	// Ball mesh
	UPROPERTY(EditAnywhere, Category="Ball")
	UStaticMeshComponent* BallMesh;

	// Movement component for the ball
	UPROPERTY(EditAnywhere, Category="Movement")
	UProjectileMovementComponent* BallMovement;
};
