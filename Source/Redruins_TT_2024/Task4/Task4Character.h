// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Task4Character.generated.h"

class UTestObject;

UCLASS()
class REDRUINS_TT_2024_API ATask4Character : public ACharacter
{
	GENERATED_BODY()

	UFUNCTION(Server, Unreliable)
	void ServerRPC_ChangeValues();

public:
	ATask4Character();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void CreateDynamicObject();

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//This Actor is responsible for replicating subobjects given in this function
	virtual bool ReplicateSubobjects (class UActorChannel *Channel, class FOutBunch *Bunch, FReplicationFlags *RepFlags) override;

	virtual void GetLifetimeReplicatedProps (TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintCallable)
	void RPC_ChangeValues();

	UFUNCTION(BlueprintCallable)
	void ChangeValues();

	//Replication Object
	UPROPERTY(Replicated, BlueprintReadOnly, Category="Object")
	UTestObject* TestObject;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMesh* StaticMesh;

	UPROPERTY(Replicated, BlueprintReadOnly)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FVector DynamicMeshOffset;
};
