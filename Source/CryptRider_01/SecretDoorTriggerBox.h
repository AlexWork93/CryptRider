// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "SecretDoorTriggerBox.generated.h"

/**
 * 
 */


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CRYPTRIDER_01_API USecretDoorTriggerBox : public UBoxComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USecretDoorTriggerBox();
	AActor* FindAppropriateActor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	UPROPERTY(EditAnywhere)
		FName UnlockTag;

};