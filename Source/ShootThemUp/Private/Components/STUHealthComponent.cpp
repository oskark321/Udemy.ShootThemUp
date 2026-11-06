// Shoot Them Up Game, All Rights Reserved.


#include "Components/STUHealthComponent.h"

DEFINE_LOG_CATEGORY_STATIC(HealthComponentLog, All, All);

// Sets default values for this component's properties
USTUHealthComponent::USTUHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//S4 L33 ustawiamy na false aby usunąć wywołanie funkcji TickComponent, nie potrzebujemy jej w tej klasie. Usuwamy aby zoptymalizować wydajność gry
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void USTUHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	//S4 L33
	Health = MaxHealth;

	//S4 L34
	AActor* ComponentOwner = GetOwner();
	//każdy komponent ma funkcję GetOwner, który zwraca wskaźnika na aktora do którego jest przypięty
	if (ComponentOwner)
	{
		ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &USTUHealthComponent::OnTakeAnyDamage);
	}
}

void USTUHealthComponent::OnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
//funkcja obsługująca EventDamage, która jest wywoływana gdy aktor otrzymuje obrażenia, parametry są narzucone z góry bo to delegad (aktor który został uszkodzony, ilość obrażeń,
//typ obrażeń, kontroler który zadał obrażenia, aktor który zadał obrażenia)
{
	//S4 L34
	//UE_LOG(HealthComponentLog, Warning, TEXT("Damage: %f"), Damage);
	Health -= Damage;
}

