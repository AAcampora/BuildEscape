// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:

	float Reach = 100.f;
	
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	// Ray-Cast and Grap what's in reach
	void Grab();

	//cALLED WHEN GRAB IS RELEASED
	void Release();

	//find attached physics handle

	void FindHandlePhysicsComponent();

	// Setup input component 
	void SetupInputComponent();

	//Return hit for first physics body in reach

	const FHitResult GetFirstPhysicsBodyInReach();

	//returns current end of reach line
	FVector GetReachLineEnd();

	//returns current Start of reach line
	FVector GetReachLineStart();
};
