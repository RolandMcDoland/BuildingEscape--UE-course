// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DrawDebugHelpers.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	//How far ahead the player we can grab in cm
	float Reach = 100.0f;

	UPhysicsHandleComponent *PhysicsHandle = nullptr;
	
	UInputComponent *InputComponent = nullptr;

	//Ray-cast and grab what's in reach
	void Grab();

	//Called when the key is released by the player
	void Release();

	//Find attached Physics Handle
	void FindPhysicsHandleComponent();

	//Setup attached Input Component
	void SetupInputComponent();

	//Return hit for first physics body in reach
	FHitResult GetFirstPhysicsBodyInReach() const;
};
