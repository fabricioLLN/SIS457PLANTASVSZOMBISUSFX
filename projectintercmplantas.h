#pragma once
class projectintercmplantas :
    public projectintercbmplantas
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlantGameMode.generated.h"

    UCLASS()
    class YOURPROJECT_API APlantGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    APlantGameMode();

    virtual void BeginPlay() override;

private:
    TMap<FString, AActor*> Plantas; // Contenedor TMap para las plantas

    void IntercambiarPosicionesDePlantas();
};
#include "PlantGameMode.h"
#include "PlantaTipo1.h" // Incluye las clases de las plantas
#include "PlantaTipo2.h"
#include "PlantaTipo3.h"

APlantGameMode::APlantGameMode()
{
    // Agrega instancias de las plantas al contenedor TMap
    Plantas.Add("Planta1", GetWorld()->SpawnActor<APlantaTipo1>());
    Plantas.Add("Planta2", GetWorld()->SpawnActor<APlantaTipo2>());
    Plantas.Add("Planta3", GetWorld()->SpawnActor<APlantaTipo3>());
}

void APlantGameMode::BeginPlay()
{
    Super::BeginPlay();

    // Programa el intercambio de posiciones cada 5 segundos
    GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &APlantGameMode::IntercambiarPosicionesDePlantas, 5.0f, true);
}

void APlantGameMode::IntercambiarPosicionesDePlantas()
{
    for (auto& Par : Plantas)
    {
        AActor* Planta = Par.Value;
        if (Planta)
        {
            FVector NuevaPosicion = FVector(FMath::RandRange(-1000.0f, 1000.0f), FMath::RandRange(-1000.0f, 1000.0f), 0.0f);
            Planta->SetActorLocation(NuevaPosicion);
        }
    }
}