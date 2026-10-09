// Shoot Them Up Game, All Rights Reserved.


#include "Components/STUHealthComponent.h"

DEFINE_LOG_CATEGORY_STATIC(STUHealthComponentLog, All, All);

// Sets default values for this component's properties
USTUHealthComponent::USTUHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//S4 L33
	PrimaryComponentTick.bCanEverTick = false;
	//wyłączamy Tick w komponencie, nie potrzebujemy tego w komponencie zdrowia

}


// Called when the game starts
void USTUHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;

	//S4 L34
	AActor* ComponentOwner = GetOwner();
	//do zmiennej ComponentOwner przypisujemy wskaźnik do właściciela komponentu, do aktora który posiada dany komponent

	if (ComponentOwner)
	{
		ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &USTUHealthComponent::OnTakeAnyDamage);
		//dodajemy funkcję OnTakeAnyDamageHandle do zdarzenia/delegata OnTakeAnyDamage, czyli gdy postać otrzyma obrażenia wywołana zostanie funkcja OnTakeAnyDamageHandle
	}
}

void USTUHealthComponent::OnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	//S4 L34
	//UE_LOG(STUHealthComponentLog, Warning, TEXT("Take Damage: %f"), Damage);

	Health -= Damage;
}

