// Shoot Them Up Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "STUPlayerController.generated.h"

class UInputMappingContext;

DECLARE_LOG_CATEGORY_CLASS(LogSTUPlayerController, All, All);

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API ASTUPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	//S3 L25 a raczej z połączeniem z poprzednim kursem
	//ta tablica do IMC_Default, czyli kontekstu mapowania wejściowego dla lokalnych kontrolerów odtwarzacza
	UPROPERTY(EditAnywhere, Category = "Input|Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;

	//ta tablica do IMC_MouseLook, czyli kontekstu mapowania wejściowego dla lokalnych kontrolerów odtwarzacza, ale tylko gdy nie mamy włączonego sterowania dotykowego, bo wtedy mamy osobne IMC_TouchLook do rozglądania się przy pomocy dotyku
	UPROPERTY(EditAnywhere, Category = "Input|Input Mappings")
	TArray<UInputMappingContext*> MobileExcludedMappingContexts;

	//zmienna aby ustalić czy gracz będzie korzystał ze sterowania dodtykowego
	UPROPERTY(EditAnywhere, Config, Category = "Input|Touch Controls")
	bool bForceTouchControls = false;

	//konfiguracja kontekstu mapowania wyjściowego
	virtual void SetupInputComponent() override;

	//funkcja zwraca true jeżeli powinniśmy używać sterowania dotykowego, czyli jeżeli jesteśmy na platformie mobilnej lub jeżeli wymusiliśmy sterowanie dotykowe
	bool ShouldUseTouchControls() const;

};
