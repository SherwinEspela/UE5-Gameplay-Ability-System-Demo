// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GASDPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IEnemyInterface;

/**
 * 
 */
UCLASS()
class GASDEMO_API AGASDPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AGASDPlayerController();
	virtual void PlayerTick(float DeltaSeconds) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

protected:
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputMappingContext> InputMappingContext;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputAction> InputActionMove;

protected:
	void Move(const FInputActionValue& InputActionValue);

private:
	void TraceEnemyByCursor();

private:
	IEnemyInterface* PreviousHighlightedEnemy;
};
