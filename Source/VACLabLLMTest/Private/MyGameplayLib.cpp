// Copyright 2025, Not real copyright, just for the prompt.

#include "MyGameplayLib.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

DEFINE_LOG_CATEGORY_STATIC(LogMyGameplayLib, Warning, All);

AActor* UMyGameplayLib::SpawnTaggedActor(UObject* WorldContext, TSubclassOf<AActor> Class, const FTransform& Xform, FName Tag)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContext, EGetWorldErrorMode::LogAndReturnNull);
	if (!World)
	{
		UE_LOG(LogMyGameplayLib, Warning, TEXT("SpawnTaggedActor failed: WorldContext is invalid."));
		return nullptr;
	}

	if (!Class)
	{
		UE_LOG(LogMyGameplayLib, Warning, TEXT("SpawnTaggedActor failed: Class is not valid."));
		return nullptr;
	}

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AActor* SpawnedActor = World->SpawnActor<AActor>(Class, Xform, SpawnParams);

	if (SpawnedActor)
	{
		SpawnedActor->Tags.AddUnique(Tag);
	}
	else
	{
		UE_LOG(LogMyGameplayLib, Warning, TEXT("SpawnTaggedActor failed: Actor could not be spawned."));
	}

	return SpawnedActor;
}
