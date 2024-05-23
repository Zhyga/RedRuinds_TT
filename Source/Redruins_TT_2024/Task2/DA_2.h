// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_2.generated.h"

class UDA_1;

UENUM(BlueprintType)
enum class EShowValue : uint8
{
	value_true,
	value_false,
	value_n
};


UCLASS(Blueprintable, BlueprintType)
class REDRUINS_TT_2024_API UDA_2 : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EShowValue Enumeration;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(EditCondition="Enumeration == EShowValue::value_true", EditConditionHides))
	UDA_1* DataAsset1;
};
