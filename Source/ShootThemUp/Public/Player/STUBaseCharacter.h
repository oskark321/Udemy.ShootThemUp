// Shoot Them Up Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "STUBaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_CLASS(LogSTUBaseCharacter, All, All);

UCLASS()
class SHOOTTHEMUP_API ASTUBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASTUBaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//S3 L25 L26 a raczej z połączeniem z poprzednim kursem
	//funkcja inicjująca powiązania akcji wyjściowych
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//akcja skoku
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* JumpAction;

	//akcja ruchu przod/tyl
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveAction;

	//rozgladania sie ale pad
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* LookAction;

	//akcja rozgladania sie myszka
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MouseLookAction;

	//S3 L2929 akcja biegabia
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* RunAction;

	//funkcja wywołana przy ruchu
	void Move(const FInputActionValue& Value);

	//funkcja wywolana przy rozglądaniu się
	void Look(const FInputActionValue& Value);

	//S3 L29 funkcja odpowiedzialna za bieganie postaci
	void StartRunning();
	void StopRunning();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//S3 L25 L26 a raczej z połączeniem z poprzednim kursem
	//funkcja obsługująca ruch z dowolnego źródła wejściowego
	UFUNCTION(BlueprintCallable, Category = "Input")
	virtual void DoMove(float Right, float Forward);

	//funkcja obsługująca rozglądanie się z dowolnego źródła wejściowego
	UFUNCTION(BlueprintCallable, Category = "Input")
	virtual void DoLook(float Yaw, float Pitch);

	//funkcja obsługująca rozpoczęcie skoku z dowolnego źródła wejściowego
	UFUNCTION(BlueprintCallable, Category = "Input")
	virtual void DoJumpStart();

	//funckja obsługująca zakończenie skoku z dowolnego źródła wejściowego
	UFUNCTION(BlueprintCallable, Category = "Input")
	virtual void DoJumpEnd();

	//S3 L29
	//UFUNCTION(BlueprintCallable aby funkcja była widoczna w BP) const aby funkcja nie modyfikowała niczego w klasie
	UFUNCTION(BlueprintCallable, Category = "Movement")
	bool IsRunning() const;


private:
	//S3 L24
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	//S3 L29
	bool WantsToRun = false;
	bool IsMovingForward = false;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float WalkSpeed = 400.0f;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float RunSpeed = 800.0f;
};
