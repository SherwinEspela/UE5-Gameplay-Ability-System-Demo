// Copyright Sherwin Espela 2024.


#include "PlayerController/GASDPlayerState.h"
#include "AbilitySystem/GASDAbilitySystemComponent.h"
#include "AbilitySystem/GASDAttributeSet.h"

AGASDPlayerState::AGASDPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UGASDAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UGASDAttributeSet>(TEXT("AttributeSet"));

	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AGASDPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
