#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ShotData.generated.h"

USTRUCT(BlueprintType)
struct FShotData : public FTableRowBase
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 game_id;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString shot_outcome;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 period;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float x_fixed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float y_fixed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float shot_distance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float shot_angle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString event_team;

    FShotData() : game_id(0), period(0), x_fixed(0.0f), y_fixed(0.0f), shot_distance(0.0f), shot_angle(0.0f) {}
};
