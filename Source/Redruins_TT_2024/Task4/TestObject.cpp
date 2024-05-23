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