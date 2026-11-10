// Shoot Them Up Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUDevDamageActor.generated.h"

UCLASS()
class SHOOTTHEMUP_API ASTUDevDamageActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASTUDevDamageActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//S4 L35
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USceneComponent* SceneComp;

	UPROPERTY(EditAnywhere)
	float SphereRadius = 300.0f;

	UPROPERTY(EditAnywhere)
	FColor SphereColor = FColor::Green;

	UPROPERTY(EditAnywhere)
	float Damage = 0.2f;

	UPROPERTY(EditAnywhere)
	bool DoFullDamage = false;

	//S4 L36
	UPROPERTY(EditAnywhere)
	TSubclassOf<UDamageType> DamageType;
	//szablon TSubclassOf pomaga aby w edytorze wybrać klasę dziedziczącą po UDamageType, a nie samą klasę UDamageType 

};
