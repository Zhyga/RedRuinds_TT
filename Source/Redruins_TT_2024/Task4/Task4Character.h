// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Task4Character.generated.h"

UCLASS()
class REDRUINS_TT_2024_API ATask4Character : public ACharacter
{
	GENERATED_BODY()

public:
	ATask4Character();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual bool ReplicateSubobjects (class UActorChannel *Channel, class FOutBunch *Bunch, FReplicationFlags *RepFlags) override;

	virtual void GetLifetimeReplicatedProps (TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UFUNCTION(BlueprintCallable)
	void CreateDynamicObject();

	UFUNCTION(BlueprintCallable)
	void RPC_ChangeValues();

	UFUNCTION(BlueprintCallable)
	void ChangeValues();

	UFUNCTION(Server, Unreliable)
	void ServerRPC_ChangeValues();
	
	UPROPERTY(Replicated, BlueprintReadOnly, Category="Object")
	class UTestObject* TestObject;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMesh* StaticMesh;

	UPROPERTY(Replicated, BlueprintReadOnly)
	UStaticMeshComponent* NewStaticMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FVector DynamicMeshOffset;
};
