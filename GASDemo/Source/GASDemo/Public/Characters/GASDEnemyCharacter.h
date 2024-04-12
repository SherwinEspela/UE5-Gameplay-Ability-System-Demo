// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/GASDBaseCharacter.h"
#include "Interface/EnemyInterface.h"
#include "GASDEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GASDEMO_API AGASDEnemyCharacter : public AGASDBaseCharacter, public IEnemyInterface
{
	GENERATED_BODY()
	
public:
	AGASDEnemyCharacter();

public:
	// Enemy Interface method
	virtual void Highlight() override;
	virtual void Unhighlight() override;

protected:
	virtual void BeginPlay() override;
};
