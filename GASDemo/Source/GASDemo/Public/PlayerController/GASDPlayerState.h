// Copyright Sherwin Espela 2024.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "GASDPlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/**
 * 
 */
UCLASS()
class GASDEMO_API AGASDPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	AGASDPlayerState();

protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
