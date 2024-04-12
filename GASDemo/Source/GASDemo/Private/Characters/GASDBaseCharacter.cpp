// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GASDBaseCharacter.h"

AGASDBaseCharacter::AGASDBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

}

UAbilitySystemComponent* AGASDBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AGASDBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}
