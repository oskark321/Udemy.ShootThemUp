// Shoot Them Up Game, All Rights Reserved.


#include "Player/STUBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

//#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

// Sets default values
ASTUBaseCharacter::ASTUBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//S3 L24
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("Spring Arm Component");
	//tworzenie komponentu ramienia sprężynującego
	SpringArmComp->SetupAttachment(RootComponent);
	//przypinamy komponent SpringArm do głównego konponentu

	CameraComp = CreateDefaultSubobject<UCameraComponent>("Camera Component");
	//tworzymy komponent kamery
	CameraComp->SetupAttachment(SpringArmComp);
	//przypinamy komponent kamery do komponentu ramienia sprężystego

}

// Called when the game starts or when spawned
void ASTUBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASTUBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//funkcja inicjująca powiązania akcji wyjściowych
void ASTUBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//S3 L25 a raczej z połączeniem z poprzednim kursem
	//konfiguracja powiązań akcji wyjściowych, czyli powiązanie akcji z funkcjami, które mają być wywołane przy danej akcji
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{

		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASTUBaseCharacter::Move);
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &ASTUBaseCharacter::Look);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASTUBaseCharacter::Look);
	}
	else
	{
		UE_LOG(LogSTUBaseCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void ASTUBaseCharacter::Move(const FInputActionValue& Value)
{
	//S3 L25 a raczej z połączeniem z poprzednim kursem
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	// route the input
	DoMove(MovementVector.X, MovementVector.Y);
}

void ASTUBaseCharacter::Look(const FInputActionValue& Value)
{
	//S3 L25 a raczej z połączeniem z poprzednim kursem
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	// route the input
	DoLook(LookAxisVector.X, LookAxisVector.Y);
}

void ASTUBaseCharacter::DoMove(float Right, float Forward)
{
	//S3 L25 a raczej z połączeniem z poprzednim kursem
	if (GetController() != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, Forward);
		AddMovementInput(RightDirection, Right);
	}
}

void ASTUBaseCharacter::DoLook(float Yaw, float Pitch)
{
	//S3 L25 a raczej z połączeniem z poprzednim kursem
	if (GetController() != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(Yaw);
		AddControllerPitchInput(Pitch);
	}
}

void ASTUBaseCharacter::DoJumpStart()
{
	//S3 L25 a raczej z połączeniem z poprzednim kursem
	// signal the character to jump
	Jump();
}

void ASTUBaseCharacter::DoJumpEnd()
{
	//S3 L25 a raczej z połączeniem z poprzednim kursem
	// signal the character to stop jumping
	StopJumping();
}
