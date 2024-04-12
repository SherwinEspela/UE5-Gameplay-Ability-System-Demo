// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GASDEnemyCharacter.h"
#include "AbilitySystem/GASDAbilitySystemComponent.h"
#include "AbilitySystem/GASDAttributeSet.h"

#define CUSTOM_HIGHLIGHT_RED 250

AGASDEnemyCharacter::AGASDEnemyCharacter()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UGASDAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UGASDAttributeSet>(TEXT("AttributeSet"));
}

void AGASDEnemyCharacter::BeginPlay()
{
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_HIGHLIGHT_RED);
}

void AGASDEnemyCharacter::Highlight()
{
	GetMesh()->SetRenderCustomDepth(true);
}

void AGASDEnemyCharacter::Unhighlight()
{
	GetMesh()->SetRenderCustomDepth(false);
}


