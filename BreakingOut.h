#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BreakingOut.generated.h"

UCLASS()
class BJBREAKOUT_API ABreakingOut : public AGameModeBase
{
	GENERATED_BODY()

public:
	// Constructor
	ABreakingOut();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Function to spawn bricks at the start of the game
	void SpawnBricks();

protected:
	// Brick class to spawn
	UPROPERTY(EditAnywhere, Category="Brick")
	TSubclassOf<class ABrick> BrickClass;

	// Brick spawning variables
	UPROPERTY(EditAnywhere, Category="Brick")
	int32 NumRows;

	UPROPERTY(EditAnywhere, Category="Brick")
	int32 NumCols;

	UPROPERTY(EditAnywhere, Category="Brick")
	float StartX;

	UPROPERTY(EditAnywhere, Category="Brick")
	float StartY;

	UPROPERTY(EditAnywhere, Category="Brick")
	float BrickSpacingX;

	UPROPERTY(EditAnywhere, Category="Brick")
	float BrickSpacingY;
};
