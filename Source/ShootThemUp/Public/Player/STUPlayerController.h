// Shoot Them Up Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "STUPlayerController.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API ASTUPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	//S3 L25 a raczej z połączeniem z poprzednim kursem
	UPROPERTY(EditAnywhere, Category = "Input")
	TArray<UInputMappingContext*> DefaultMappingContexts;

	//konfiguracja kontekstu mapowania wyjściowego
	virtual void SetupInputComponent() override;


};
