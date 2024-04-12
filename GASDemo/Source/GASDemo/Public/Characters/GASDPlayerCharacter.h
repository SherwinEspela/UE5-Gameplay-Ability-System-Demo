// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/GASDBaseCharacter.h"
#include "GASDPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

/**
 * 
 */
UCLASS()
class GASDEMO_API AGASDPlayerCharacter : public AGASDBaseCharacter
{
	GENERATED_BODY()
	
public:
	AGASDPlayerCharacter();

protected:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCameraComponent> Camera;
};
