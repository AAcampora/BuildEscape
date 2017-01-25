// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	 ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor()
{
	// Find the Owning actor
	AActor* Owner = GetOwner();

	//Create Rotation

	FRotator NewRotation = FRotator(0.0f, 60.0f, 0.0f);

	//Set Door Rotation

	Owner->SetActorRotation(NewRotation);
}

// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Poll the trigger volume
	if(PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		//If the Actor that opnes is in the volume
		OpenDoor();
	}

}

