// MyRotatingActor.cpp

#include "MyRotatingActor.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AMyRotatingActor::AMyRotatingActor()
{
    // Set this actor to call Tick() every frame.
    PrimaryActorTick.bCanEverTick = true;

    // Initialize the components
    Sphere1Component = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere1"));
    Sphere2Component = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere2"));

    // Set the root component to be Sphere2
    RootComponent = Sphere2Component;

    // Attach Sphere1 to Sphere2
    Sphere1Component->SetupAttachment(RootComponent);

    // Set the orbit radius and speed
    OrbitRadius = 500.0f; // Example radius
    OrbitSpeed = 90.0f; // Example speed

    // Set the initial orbit angle
    CurrentOrbitAngle = 0.0f;

    // Load a sphere mesh for demonstration purposes
    static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
    if (SphereMesh.Succeeded())
    {
        Sphere1Component->SetStaticMesh(SphereMesh.Object);
        Sphere2Component->SetStaticMesh(SphereMesh.Object);
    }

    // Scale down Sphere1 to make it visually distinct from Sphere2
    Sphere1Component->SetWorldScale3D(FVector(0.5f));
}

void AMyRotatingActor::BeginPlay()
{
    Super::BeginPlay();
}

void AMyRotatingActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Update the current orbit angle
    CurrentOrbitAngle += OrbitSpeed * DeltaTime;
    if (CurrentOrbitAngle >= 360.0f)
    {
        CurrentOrbitAngle -= 360.0f;
    }

    // Calculate the new position for Sphere1
    FVector NewLocation = RootComponent->GetComponentLocation();
    NewLocation.X += OrbitRadius * FMath::Cos(FMath::DegreesToRadians(CurrentOrbitAngle));
    NewLocation.Y += OrbitRadius * FMath::Sin(FMath::DegreesToRadians(CurrentOrbitAngle));
    Sphere1Component->SetWorldLocation(NewLocation);
}
