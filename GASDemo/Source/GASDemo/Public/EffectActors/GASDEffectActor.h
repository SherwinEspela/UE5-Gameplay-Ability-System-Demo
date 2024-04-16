// Copyright Sherwin Espela 2024.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GASDEffectActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class GASDEMO_API AGASDEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AGASDEffectActor();

public:
	UFUNCTION()
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> SphereComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;
};
