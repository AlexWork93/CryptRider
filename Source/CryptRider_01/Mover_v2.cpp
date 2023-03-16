// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover_v2.h"
#include "Math/UnrealMathUtility.h"


// Sets default values for this component's properties
UMover_v2::UMover_v2()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	ShouldMove = false;
	TimeToMove = 4;
	DistanceToMove = FVector(0, 0, -500);
}


// Called when the game starts
void UMover_v2::BeginPlay()
{
	Super::BeginPlay();

	// ...
	// 
	for (UActorComponent* Component : GetOwner()->GetComponents()) {
		if (Component->ComponentHasTag("Cage")) {
			Cage = Cast<USceneComponent>(Component);
		}
	}
	InitLocation = Cage->GetRelativeLocation();
}


// Called every frame
void UMover_v2::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (ShouldMove)
	{
		FVector Current = Cage->GetRelativeLocation();
		float InterpSpeed = FVector::Dist(InitLocation, InitLocation + DistanceToMove) / TimeToMove;
		FVector NewLocation = FMath::VInterpConstantTo(Current, InitLocation + DistanceToMove, DeltaTime, InterpSpeed);
		Cage->SetRelativeLocation(NewLocation);
	}
	else
	{
		FVector Current = Cage->GetRelativeLocation();
		float InterpSpeed = FVector::Dist(InitLocation, InitLocation + DistanceToMove) / TimeToMove;
		FVector NewLocation = FMath::VInterpConstantTo(Current, InitLocation, DeltaTime, InterpSpeed);
		Cage->SetRelativeLocation(NewLocation);
	}
}

void UMover_v2::SetShouldMove(bool should) {
	ShouldMove = should;
}


