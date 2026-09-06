// Shoot Them Up Game, All Rights Reserved.


#include "Components/STUCharacterMovementComponent.h"
#include "Player/STUBaseCharacter.h"

float USTUCharacterMovementComponent::GetMaxSpeed() const
{
	const float MaxSpeed = Super::GetMaxSpeed();
	//do zmiennej MaxSpeed przypisujemy wartość zwróconą przez funkcję GetMaxSpeed()
	const ASTUBaseCharacter* Player = Cast<ASTUBaseCharacter>(GetPawnOwner());
	//do zmiennej Player przypisujemy wskaźnik do właściciela danego komponentu, czyli do postaci

	return Player && Player->IsRunning() ? MaxSpeed * RunModifier : MaxSpeed;
	//sprawdzamy czy wskaźnik Player jest prawdziwy i czy postać porusza się do przodu, jeśli tak to zwracamy MaxSpeed pomnożoną przez modyfikator prędkości biegu
	//w przeciwnym razie zwracamy MaxSpeed
}
