// Woo ShinHui All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "WarriorGameplayAbility.generated.h"

UENUM(BlueprintType)
enum class EWarriorAbilityActivitionPolicy : uint8
{
	OnTriggered,
	OnGiven
};
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
protected:
	//~ Begin UGameplayAbility Interface.
	// 액터의 각종 정보가 있는 ActorInfo, Spec은 인스턴스 정보
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec);
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled);
	//~ End UGameplayAbility Interface.

    // OnTriggered 정책은 부모(UGameplayAbility)의 기본 Activate 방식과 동일하므로 별도 오버라이드 로직 불필요
    // (OnGiven 정책만 OnGiveAbility/EndAbility에서 별도 처리)
	UPROPERTY(EditDefaultsOnly,Category = "WarriorAbility")
	EWarriorAbilityActivitionPolicy AbilityActivationPolicy = EWarriorAbilityActivitionPolicy::OnTriggered;
};
