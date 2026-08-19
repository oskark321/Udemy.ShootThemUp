// Shoot Them Up Game, All Rights Reserved.


#include "Player/STUPlayerController.h"

#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/Input/SVirtualJoystick.h"


void ASTUPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//S3 L25 a raczej z połączeniem z poprzednim kursem
	//to IMC dla lokalnych kontrolerów odtwarzacza, więc sprawdzamy czy kontroler jest lokalny
	if (IsLocalPlayerController())
	{
		//dodajemy kontekst mapowania wejściowego do podsystemu lokalnego gracza tutaj IMC_Default
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}

			//to IMC dodajemy do korzystania rozglądania się myszką bo mamy osobne IMC_MouseLook do rozglądania się przy pomocy myszki, tylko gdy nie mamy włączonego sterowania dotykowego, bo wtedy mamy osobne IMC_TouchLook do rozglądania
			//się przy pomocy dotyku
			if (!ShouldUseTouchControls())
			{
				for (UInputMappingContext* CurrentContext : MobileExcludedMappingContexts)
				{
					Subsystem->AddMappingContext(CurrentContext, 0);
				}
			}
		}
	}
}

//S3 L25 a raczej z połączeniem z poprzednim kursem
bool ASTUPlayerController::ShouldUseTouchControls() const
//funkcja zwraca true jeżeli powinniśmy używać sterowania dotykowego, czyli jeżeli jesteśmy na platformie mobilnej lub jeżeli wymusiliśmy sterowanie dotykowe
{
	//czy jesteśmy na urządzeniu mobilnym czy powiiniśmy wymuszać dotyk
	return SVirtualJoystick::ShouldDisplayTouchInterface() || bForceTouchControls;
}


