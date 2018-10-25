// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty!"));
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Declare player view point components
	FRotator PlayerViewPointRotation = FRotator(0.0f, 0.0f, 0.0f);
	FVector PlayerViewPointLocation = FVector(0.0f, 0.0f, 0.0f);

	//Get player view point and log it out to Unreal output log
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPointLocation,OUT PlayerViewPointRotation);
	UE_LOG(LogTemp, Warning, TEXT("Location: %s, Rotation: %s"),*PlayerViewPointLocation.ToString(),*PlayerViewPointRotation.ToString());

	//Calculate the end of a debug line
	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector()*Reach;
	//Draw a debug line representing the reach and direction of grabber
	DrawDebugLine(GetWorld(), PlayerViewPointLocation, LineTraceEnd, FColor(255, 0, 0),false,0.0f,0.0f,10.0f);
}

