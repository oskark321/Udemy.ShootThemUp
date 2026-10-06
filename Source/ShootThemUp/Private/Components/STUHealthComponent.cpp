// Shoot Them Up Game, All Rights Reserved.


#include "Components/STUHealthComponent.h"

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
}


