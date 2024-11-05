#include "Ball.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Brick.h"

// Constructor
ABall::ABall()
{
	PrimaryActorTick.bCanEverTick = true;

	// Set up ball mesh
	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	SetRootComponent(BallMesh);

	// Set up ball movement
	BallMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("BallMovement"));
	BallMovement->InitialSpeed = 500.0f;
	BallMovement->MaxSpeed = 1000.0f;
	BallMovement->bShouldBounce = true;
	BallMovement->Bounciness = 1.0f;
	BallMovement->Friction = 0.0f;

	// Bind the OnHit function
	BallMesh->OnComponentHit.AddDynamic(this, &ABall::OnHit);
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Function to handle ball collision
void ABall::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Check if the ball hit a brick
	if (ABrick* Brick = Cast<ABrick>(OtherActor))
	{
		Brick->Destroy();
		BallMovement->Velocity *= 1.05f; // Increase ball speed when a brick is destroyed
	}
}
