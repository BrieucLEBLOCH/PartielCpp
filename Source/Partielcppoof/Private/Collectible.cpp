#include "Collectible.h"
#include "Components/SphereComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "../PartielcppoofCharacter.h"
#include "Kismet/GameplayStatics.h"

ACollectible::ACollectible()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = SceneComponent;

	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	SphereCollider->SetupAttachment(SceneComponent);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(SceneComponent);
	StaticMesh->SetCollisionProfileName(TEXT("NoCollision"));

	RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));
	RotatingMovement->RotationRate = FRotator(0, 100, 0);
}

void ACollectible::MoveCoinsUpdate()
{
	FVector Location = GetActorLocation();
	Location.X -= 10.f;
	SetActorLocation(Location);
}

void ACollectible::BeginPlay()
{
	Super::BeginPlay();

	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ACollectible::OnSphereOverlap);
}

void ACollectible::OnSphereOverlap(UPrimitiveComponent* OverlapComponent, AActor* OtherActor, UPrimitiveComponent* Othercomp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APartielcppoofCharacter* PartielCharacter = Cast<APartielcppoofCharacter>(OtherActor);

	if (PartielCharacter)
	{
		PartielCharacter->AddCoin();
		if (OverlapSound)
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), OverlapSound, GetActorLocation());
		}
		Destroy();
	}
}

void ACollectible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveCoinsUpdate();
}
