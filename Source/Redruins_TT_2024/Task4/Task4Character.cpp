// RedRuins Softworks (c)


#include "Task4Character.h"
#include "TestObject.h"
#include "Engine/ActorChannel.h"
#include "Net/UnrealNetwork.h"


ATask4Character::ATask4Character()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	NetCullDistanceSquared = 99999;
	NetUpdateFrequency = 1.f;
}

void ATask4Character::BeginPlay()
{
	Super::BeginPlay();

	if(HasAuthority())
	{
		TestObject = NewObject<UTestObject>(this);
	}

	if(TestObject) UE_LOG(LogTemp, Log, TEXT("%s created"), *TestObject->GetName());
}

void ATask4Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATask4Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

bool ATask4Character::ReplicateSubobjects(UActorChannel* Channel, FOutBunch* Bunch, FReplicationFlags* RepFlags)
{
	bool WroteSomething = Super::ReplicateSubobjects(Channel, Bunch, RepFlags);
	
	if (TestObject ) WroteSomething |= Channel->ReplicateSubobject(TestObject , *Bunch, *RepFlags);

	return WroteSomething;
}

void ATask4Character::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATask4Character, TestObject);
	DOREPLIFETIME(ATask4Character, NewStaticMesh);
}

void ATask4Character::CreateDynamicObject()
{
	if(HasAuthority())
	{
		NewStaticMesh = NewObject<UStaticMeshComponent>(this, TEXT("StaticMesh"));
		if (NewStaticMesh)
		{
			FVector ActorLocation = GetActorLocation();
			NewStaticMesh->SetRelativeLocation(ActorLocation + DynamicMeshOffset);
			NewStaticMesh->SetStaticMesh(StaticMesh);
			NewStaticMesh->SetIsReplicated(true); 
			NewStaticMesh->RegisterComponentWithWorld(GetWorld());
		}
	}
}

void ATask4Character::RPC_ChangeValues()
{
	ServerRPC_ChangeValues();
}

void ATask4Character::ChangeValues()
{
	TestObject->value1 = !TestObject->value1;
	TestObject->value2 = FMath::RandRange(0, 100);
	TestObject->value3 = FMath::RandRange(0.f, 100.f);
}

void ATask4Character::ServerRPC_ChangeValues_Implementation()
{
	ChangeValues();
}

