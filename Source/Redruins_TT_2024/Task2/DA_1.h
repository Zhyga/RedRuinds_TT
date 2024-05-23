// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_1.generated.h"

class UDA_2;

UCLASS(Blueprintable, BlueprintType)
class REDRUINS_TT_2024_API UDA_1 : public UDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDA_2* DataAsset1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Texture;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Vector;
};
