// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/GASDPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Characters/Interface/EnemyInterface.h"
#include "InputTriggers.h"

AGASDPlayerController::AGASDPlayerController()
{
	bReplicates = true;
}

void AGASDPlayerController::PlayerTick(float DeltaSeconds)
{
	Super::PlayerTick(DeltaSeconds);

	TraceEnemyByCursor();
}

void AGASDPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(InputMappingContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	
	Subsystem->AddMappingContext(InputMappingContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AGASDPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(InputActionMove, ETriggerEvent::Triggered, this, &AGASDPlayerController::Move);
}

void AGASDPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	APawn* ControlledPawn = GetPawn<APawn>();
	if (ControlledPawn)
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AGASDPlayerController::TraceEnemyByCursor()
{
	FHitResult Hit;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, Hit);

	if (!Hit.bBlockingHit) return;

	IEnemyInterface* NewHighlightedEnemy = Cast<IEnemyInterface>(Hit.GetActor());
	if (NewHighlightedEnemy)
	{
		NewHighlightedEnemy->Highlight();
		if (PreviousHighlightedEnemy && PreviousHighlightedEnemy != NewHighlightedEnemy) {
			PreviousHighlightedEnemy->Unhighlight();
		}
		PreviousHighlightedEnemy = NewHighlightedEnemy;
	}
	else {
		if (PreviousHighlightedEnemy) PreviousHighlightedEnemy->Unhighlight();
	}
}
