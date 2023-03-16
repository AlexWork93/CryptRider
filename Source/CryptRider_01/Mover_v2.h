// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Mover_v2.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRIDER_01_API UMover_v2 : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMover_v2();
	UFUNCTION(BlueprintCallable)
		void SetShouldMove(bool should);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	USceneComponent* Cage;
	FVector InitLocation;
	float TimeToMove;

private:
	UPROPERTY(EditAnywhere)
		FVector DistanceToMove;
	UPROPERTY(EditAnywhere)
		bool ShouldMove;

};
