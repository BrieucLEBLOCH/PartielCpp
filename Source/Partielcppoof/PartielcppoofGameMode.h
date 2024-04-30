// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PartielcppoofGameMode.generated.h"

UCLASS(minimalapi)
class APartielcppoofGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APartielcppoofGameMode();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Runtime)
	int32 TotalCoins = 0;

	UFUNCTION(BlueprintCallable)
	void AddCoin();

	UFUNCTION(BlueprintImplementableEvent, Category = Event)
	void Win();
};



