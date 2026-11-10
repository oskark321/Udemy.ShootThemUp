// Shoot Them Up Game, All Rights Reserved.


#include "Dev/STUDevDamageActor.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASTUDevDamageActor::ASTUDevDamageActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//S4 L35
	SceneComp = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComp);

}

// Called when the game starts or when spawned
void ASTUDevDamageActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASTUDevDamageActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//S4 L35
	DrawDebugSphere(GetWorld(), GetActorLocation(), SphereRadius, 24, SphereColor);
	//narysuj kulę(wskaźnik do świata gdze ma być rysowana, lokalizacja w świecie - gdzie ustawimy aktora dzięki kompojentowi sceny, promień - wielkość kuli, ilość segmentów - jak bardzo ma
	//być okrągła, kolor kuli)

	UGameplayStatics::ApplyRadialDamage(GetWorld(), Damage, GetActorLocation(), SphereRadius, DamageType, {}, this, nullptr, DoFullDamage);
	//zadaj obrażenia obszarowe wszystkim aktorą w strefie - nie musimy określać kto ma otrzymać obrażenia jak w funkcjach ApplyDamage i ApplyRadialDamage(pobieramy wskaźnik świata, ilość obrażeń,
	//lokalizacja w świecie, promień sfery w której mają być zadane obrażenia, rodzaj obrażeń - nullptr oznacza że nie określamy rodzaju obrażeń i zostanie użyty domyślny, tablica IgnoreActor czyli
	//określamy aktorów których nie chcemy skrzywdzić - my przekazujemy pustą tablicę, aktor który powoduj obrazenia czyli ten aktor, kontroler my nullptr ponieważ ten aktor nie jest pionkiem ani
	//postacią nie jest przez nas kontrolowany, zmienna odpowiada za uszkodzenia promieniowe jeśli jest true to nie ważne w którym miejscu sfery się znajduje otrzyma pełne obrażenia jeśli false to
	//pelne obrażenia otrzymamy tylko w centrum sfery, ostatni parametr my go nie mamy dotyczy kolizji jeśli np między nami a epicentrum wybuchu jest inny obiekt można zrobić że obrażenia są
	//ignorowane dla naszej postaci)
	//DamageType - jest to szablon TSubclassOf<UDamageType> aby określić rodzaj obrażeń

}

