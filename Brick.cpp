#include "Brick.h"
#include "Components/StaticMeshComponent.h"

// Constructor
ABrick::ABrick()
{
	PrimaryActorTick.bCanEverTick = true;

	// Set up brick mesh
	BrickMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BrickMesh"));
	SetRootComponent(BrickMesh);
}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
}
