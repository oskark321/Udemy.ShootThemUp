// Shoot Them Up Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STUHealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTTHEMUP_API USTUHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USTUHealthComponent();

	//S4 L33
	//funkcja zwracająca wartość zdrowia. Jest w pliku głównym ponieważ jest jednowierszowa więc może tu być, const ponieważ funkcja niczego nie zmienia w klasie zwraca jedynie wartość
	float GetHealth() const { return Health; }

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//S4 L33
	//meta pozwala na ustawienie wartości w edytorze, tutaj mamy minimalną i maksymalną wartość zdrowia jaką możemy ustawić w edytorze
	UPROPERTY(EditAnywhere, Category = "Health", meta = (ClampMin = 0.0f, ClampMax = 1000.0f))
	float MaxHealth = 100.0f;

private:
	//S4 L33
	float Health = 0.0;

	//S4 L34
	UFUNCTION()
	void OnTakeAnyDamageFunction(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	//funkcja obsługująca EventDamage, która jest wywoływana gdy aktor otrzymuje obrażenia, parametry są narzucone z góry bo to delegad (aktor który został uszkodzony, ilość obrażeń,
	//typ obrażeń, kontroler który zadał obrażenia, aktor który zadał obrażenia)

};
