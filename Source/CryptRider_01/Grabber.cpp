// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "DrawDebugHelpers.h"
#include "Components/PrimitiveComponent.h"



// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	GrabDistance = 200;
	HoldDistance = 130;
	TraceSphereRadius = 30;
	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	World = GetWorld();
	Owner = GetOwner();
	PhysComp = Owner->FindComponentByClass<UPhysicsHandleComponent>();
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (PhysComp != nullptr)
	{
		PhysComp->SetTargetLocationAndRotation(GetComponentLocation() + GetForwardVector() * HoldDistance, GetComponentRotation());
	}
}

void UGrabber::Grab() {
	FVector LineStart = GetComponentLocation();
	FVector LineEnd = LineStart + GetForwardVector() * GrabDistance;
	//DrawDebugLine(World, LineStart, LineEnd,FColor::Red, false, 5);
	FVector Center = LineEnd;
	float Radius = 30;
	int32 Segments = 10;
	//DrawDebugSphere(World, Center, Radius, Segments, FColor::Yellow, false, 5);
    FHitResult OutHit;
	FCollisionShape CollisionShape = FCollisionShape::MakeSphere(TraceSphereRadius);
	bool HasHit = World->SweepSingleByChannel(OutHit, LineStart, LineEnd, FQuat::Identity, ECC_GameTraceChannel2, CollisionShape);
	if (HasHit)
	{
		DrawDebugSphere(World, OutHit.ImpactPoint, Radius, Segments, FColor::Green, false, 5);
		PhysComp->GrabComponentAtLocationWithRotation(OutHit.GetComponent(), NAME_None, OutHit.ImpactPoint, GetComponentRotation());
		PhysComp->GetGrabbedComponent()->GetOwner()->Tags.Add("Grabbed");

		if (!Cast<UPrimitiveComponent>(OutHit.GetActor()->GetRootComponent())->IsSimulatingPhysics()) {
			Cast<UPrimitiveComponent>(OutHit.GetActor()->GetRootComponent())->SetSimulatePhysics(true);
		}
	}
}

void UGrabber::Release() {
	if (PhysComp->GetGrabbedComponent() != nullptr)
	{
		PhysComp->GetGrabbedComponent()->GetOwner()->Tags.Remove("Grabbed");
		PhysComp->ReleaseComponent();
	}

}