// MyRotatingActor.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyRotatingActor.generated.h"

UCLASS()
class PT1_API AMyRotatingActor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AMyRotatingActor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Components for the spheres
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* Sphere1Component;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* Sphere2Component;

    // The radius of the orbit
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
    float OrbitRadius;

    // The speed of the orbit (degrees per second)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
    float OrbitSpeed;

private:
    // The current angle for the orbit
    float CurrentOrbitAngle;
};
