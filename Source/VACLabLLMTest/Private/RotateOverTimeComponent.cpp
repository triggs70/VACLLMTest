// Fill out your copyright notice in the Description page of Project Settings.

#include "RotateOverTimeComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
URotateOverTimeComponent::URotateOverTimeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.
	// You can turn these features off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


}


// Called when the game starts
void URotateOverTimeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URotateOverTimeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (bPaused) {return;}

	AActor* Owner = GetOwner();
	if (Owner)
	{
		FRotator RotationThisFrame = FRotator(0.f, DegreesPerSecond * DeltaTime, 0.f);
		Owner->AddActorLocalRotation(RotationThisFrame);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("URotateOverTimeComponent: Owner is null!"));
	}
}
