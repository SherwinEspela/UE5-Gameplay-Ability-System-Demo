// Copyright Sherwin Espela 2024. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GASDEMO_API IEnemyInterface
{
	GENERATED_BODY()

public:
	virtual void Highlight() = 0;
	virtual void Unhighlight() = 0;
};
