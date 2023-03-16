// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"
#include "Math/UnrealMathUtility.h"


// Sets default values for this component's properties
UMover::UMover()
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
void UMover::BeginPlay()
{
	Super::BeginPlay();

	// ...
	// 
	Owner = GetOwner();
	InitLocation = Owner->GetActorLocation();
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (ShouldMove)
	{
		FVector Current = Owner->GetActorLocation();
		float InterpSpeed = FVector::Dist(InitLocation, InitLocation + DistanceToMove) / TimeToMove;
		FVector NewLocation = FMath::VInterpConstantTo(Current, InitLocation + DistanceToMove, DeltaTime, InterpSpeed);
		Owner->SetActorLocation(NewLocation);
	}
	else
	{
		FVector Current = Owner->GetActorLocation();
		float InterpSpeed = FVector::Dist(InitLocation, InitLocation + DistanceToMove) / TimeToMove;
		FVector NewLocation = FMath::VInterpConstantTo(Current, InitLocation, DeltaTime, InterpSpeed);
		Owner->SetActorLocation(NewLocation);
	}
}

void UMover::SetShouldMove(bool should) {
	ShouldMove = should;
}


