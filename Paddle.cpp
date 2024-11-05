#include "Paddle.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

// Constructor
APaddle::APaddle()
{
	PrimaryActorTick.bCanEverTick = true;

	// Set up paddle mesh
	PaddleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PaddleMesh"));
	SetRootComponent(PaddleMesh);

	// Set default movement speed
	MovementSpeed = 600.0f;
}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Function to move the paddle
void APaddle::MovePaddle(float AxisValue)
{
	FVector NewLocation = GetActorLocation();
	NewLocation.X += AxisValue * MovementSpeed * GetWorld()->GetDeltaSeconds();
	SetActorLocation(NewLocation);
}
