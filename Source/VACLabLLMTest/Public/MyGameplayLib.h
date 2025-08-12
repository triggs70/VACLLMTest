// Copyright 2025, Not real copyright, just for the prompt.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyGameplayLib.generated.h"

class AActor;

/**
 * A library of gameplay-related utility functions.
 */
UCLASS()
class VACLABLLMTEST_API UMyGameplayLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Spawns an actor and adds a specified tag to it.
	 * @param WorldContext The world context object.
	 * @param Class The actor class to spawn.
	 * @param Xform The transform to spawn the actor at.
	 * @param Tag The tag to add to the spawned actor.
	 * @return The spawned actor, or nullptr if spawning failed.
	 */
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContext", DeterminesOutputType = "Class"), Category = "VACLabLLMTest")
	static AActor* SpawnTaggedActor(UObject* WorldContext, TSubclassOf<AActor> Class, const FTransform& Xform, FName Tag);
};
