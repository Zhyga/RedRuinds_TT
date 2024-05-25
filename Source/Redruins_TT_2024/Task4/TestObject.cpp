// RedRuins Softworks (c)


#include "TestObject.h"
#include "Engine/World.h"
#include "Net/UnrealNetwork.h"

UTestObject::UTestObject()
{
	
}

void UTestObject::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	UObject::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UTestObject, value1);
	DOREPLIFETIME(UTestObject, value2);
	DOREPLIFETIME(UTestObject, value3);
}

bool UTestObject::CallRemoteFunction(UFunction* Function, void* Parms, FOutParmRec* OutParms, FFrame* Stack)
{
	if (!GetOuter()) return false;
	UNetDriver* NetDriver = GetWorld()->GetNetDriver();
	if (!NetDriver) return false;

	NetDriver->ProcessRemoteFunction(Cast<AActor>(GetOuter()), Function, Parms, OutParms, Stack, this);

	return true;
}

int32 UTestObject::GetFunctionCallspace(UFunction* Function, FFrame* Stack)
{
	return (GetOuter() ? GetOuter()->GetFunctionCallspace(Function,Stack) : FunctionCallspace::Local);
} 

void UTestObject::ChangeValues()
{
	value1 = !value1;
	value2 = FMath::RandRange(0, 100);
	value3 = FMath::RandRange(0.f, 100.f);
}

void UTestObject::RPC_Server_ChangeValues_Implementation()
{
	ChangeValues();
}

