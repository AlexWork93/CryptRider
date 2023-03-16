// Fill out your copyright notice in the Description page of Project Settings.


#include "SecretDoorTriggerBox_v2.h"
#include "Mover_v2.h"
#include "Components/PrimitiveComponent.h"
#include "Components/ArrowComponent.h"




USecretDoorTriggerBox_v2::USecretDoorTriggerBox_v2()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	UnlockTag = "Unlock";
	// ...
}


// Called when the game starts
void USecretDoorTriggerBox_v2::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void USecretDoorTriggerBox_v2::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	AActor* Actor = FindAppropriateActor();
	if (Actor != nullptr)
	{
		GetOwner()->FindComponentByClass<UMover_v2>()->SetShouldMove(true);
		Cast<UPrimitiveComponent>(Actor->GetRootComponent())->SetSimulatePhysics(false);
		FRotator NewRotation = GetOwner()->FindComponentByClass<UArrowComponent>()->GetComponentRotation();
		FVector NewLocation = GetOwner()->FindComponentByClass<UArrowComponent>()->GetComponentLocation();

		Actor->SetActorRotation(NewRotation);
		Actor->SetActorLocation(NewLocation);


	}
	else
	{
		GetOwner()->FindComponentByClass<UMover_v2>()->SetShouldMove(false);
	}
}

AActor* USecretDoorTriggerBox_v2::FindAppropriateActor() {
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);
	for (AActor* Actor : Actors)
	{
		if (Actor->ActorHasTag(UnlockTag) && !Actor->ActorHasTag("Grabbed"))
		{
			return Actor;
		}
	}
	return nullptr;
}
