// Shoot Them Up Game, All Rights Reserved.


#include "Player/STUPlayerController.h"

#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

void ASTUPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//S3 L25 a raczej z połączeniem z poprzednim kursem
	//to IMC dla lokalnych kontrolerów odtwarzacza, więc sprawdzamy czy kontroler jest lokalny
	if (IsLocalPlayerController())
	{
		//dodajemy kontekst mapowania wejściowego do podsystemu lokalnego gracza
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}
		}
	}
}


