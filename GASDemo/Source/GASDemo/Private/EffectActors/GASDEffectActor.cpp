// Copyright Sherwin Espela 2024.

#include "EffectActors/GASDEffectActor.h"
#include "AbilitySystem/GASDAttributeSet.h"
#include "Components/SphereComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"

AGASDEffectActor::AGASDEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(GetRootComponent());
	
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AGASDEffectActor::OnBeginOverlap);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this, &AGASDEffectActor::OnEndOverlap);
}

void AGASDEffectActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor);
	if (AbilitySystemInterface)
	{
		const auto AttributeSet = AbilitySystemInterface->GetAbilitySystemComponent()->GetAttributeSet(UGASDAttributeSet::StaticClass());
		const UGASDAttributeSet* OtherActorAttributeSet = Cast<UGASDAttributeSet>(AttributeSet);
		if (OtherActorAttributeSet)
		{
			Destroy();
		}
	}
}

void AGASDEffectActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AGASDEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
}
