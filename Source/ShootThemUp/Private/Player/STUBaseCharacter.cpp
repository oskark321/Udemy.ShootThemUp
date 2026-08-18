// Shoot Them Up Game, All Rights Reserved.


#include "Player/STUBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

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

// Called to bind functionality to input
void ASTUBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

