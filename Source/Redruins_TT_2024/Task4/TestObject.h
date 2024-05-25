// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "TestObject.generated.h"

UCLASS(BlueprintType, Blueprintable)
class REDRUINS_TT_2024_API UTestObject : public UObject
{
	GENERATED_BODY()
	
public:
	UTestObject();
	
	void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const override;
	
	virtual bool CallRemoteFunction (UFunction * Function, void * Parms, struct FOutParmRec * OutParms, FFrame * Stack) override;

	virtual int32 GetFunctionCallspace (UFunction* Function, FFrame* Stack) override;

	UFUNCTION(BlueprintCallable)
	void ChangeValues();

	UFUNCTION(Server, Unreliable, BlueprintCallable)
	void RPC_Server_ChangeValues();
	
	UPROPERTY(BlueprintReadWrite, Replicated, meta=(ExposeOnSpawn=true))
	bool value1;

	UPROPERTY(BlueprintReadWrite, Replicated, meta=(ExposeOnSpawn=true))
	int value2;

	UPROPERTY(BlueprintReadWrite, Replicated, meta=(ExposeOnSpawn=true))
	float value3;

	virtual bool IsSupportedForNetworking() const override
	{
		return true;
	}
};

