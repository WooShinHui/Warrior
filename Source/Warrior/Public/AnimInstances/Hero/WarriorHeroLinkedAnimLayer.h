// Woo ShinHui All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorBaseAnimInstances.h"
#include "WarriorHeroLinkedAnimLayer.generated.h"

class UWarriorHeroAnimInstance;

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorHeroLinkedAnimLayer : public UWarriorBaseAnimInstances
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta = (NotBlueprintThreadSafe))
	UWarriorHeroAnimInstance* GetHeroAnimInstance() const;
};
