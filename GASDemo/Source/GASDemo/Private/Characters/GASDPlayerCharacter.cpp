// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GASDPlayerCharacter.h"
#include "PlayerController/GASDPlayerState.h"
#include "AbilitySystem/GASDAbilitySystemComponent.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AGASDPlayerCharacter::AGASDPlayerCharacter()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;

	SpringArm->TargetArmLength = 650.f;
	SpringArm->bUsePawnControlRotation = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;
}

void AGASDPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilityActorInfo();
}

void AGASDPlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitAbilityActorInfo();
}

void AGASDPlayerCharacter::InitAbilityActorInfo()
{
	// Server - init ability actor info
	AGASDPlayerState* GASDPlayerState = GetPlayerState<AGASDPlayerState>();
	check(GASDPlayerState);
	GASDPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(GASDPlayerState, this);
	AbilitySystemComponent = GASDPlayerState->GetAbilitySystemComponent();
	AttributeSet = GASDPlayerState->GetAttributSet();
}
