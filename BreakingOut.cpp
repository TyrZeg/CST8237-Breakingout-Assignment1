#include "BreakingOut.h"
#include "Brick.h"
#include "Engine/World.h"
#include  "Paddle.h"

// Constructor
ABreakingOut::ABreakingOut()
{
	// Set default values
	NumRows = 5;
	NumCols = 10;
	StartX = -500.0f;
	StartY = 500.0f;
	BrickSpacingX = 100.0f;
	BrickSpacingY = 50.0f;
}

// Called when the game starts
void ABreakingOut::BeginPlay()
{
	Super::BeginPlay();

	// Spawn bricks
	SpawnBricks();
}

// Function to spawn bricks in a grid
void ABreakingOut::SpawnBricks()
{
	for (int Row = 0; Row < NumRows; ++Row)
	{
		for (int Col = 0; Col < NumCols; ++Col)
		{
			FVector BrickLocation = FVector(StartX + Col * BrickSpacingX, StartY + Row * BrickSpacingY, 0.0f);
			GetWorld()->SpawnActor<ABrick>(BrickClass, BrickLocation, FRotator::ZeroRotator);
		}
	}
}
