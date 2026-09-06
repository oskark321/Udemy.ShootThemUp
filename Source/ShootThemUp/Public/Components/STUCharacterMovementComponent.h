// Shoot Them Up Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "STUCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API USTUCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:
	//S3 L29 funkcja zwraca maksymalną prędkość poruszania się postaci
	virtual float GetMaxSpeed() const override;

	//meta = (ClampMin = 1.2, ClampMax = 10.0) - określa minimalną i maksymalną wartość zmiennej RunModifier, która może być ustawiona w edytorze
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (ClampMin = 1.2, ClampMax = 10.0))
	float RunModifier = 1.5f;
	//zmienna określająca modyfikator prędkości biegu postaci, czyli o ile szybciej porusza się postać podczas biegu
};
