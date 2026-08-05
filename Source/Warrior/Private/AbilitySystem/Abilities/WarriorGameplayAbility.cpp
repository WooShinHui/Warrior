// Woo ShinHui All Rights Reserved


#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "Components/Combat/PawnCombatComponent.h"

// 1회성 행동 부여. 액터의 정보를 가져와서 어빌리티 스펙을 참조하여 TryActivate함. OnGiven일 경우에만 부여 OnTriggered는 Default
void UWarriorGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (AbilityActivationPolicy == EWarriorAbilityActivitionPolicy::OnGiven)
	{
		if(ActorInfo && !Spec.IsActive())
		{
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}
	}
}

// 어빌리티 종료
void UWarriorGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
		if (AbilityActivationPolicy == EWarriorAbilityActivitionPolicy::OnGiven)
		{
			if (ActorInfo)
			{
				ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
			}
		}
}

UPawnCombatComponent* UWarriorGameplayAbility::GetPawnCombatComponentFromActorInfo() const
{
 return GetAvatarActorFromActorInfo()->FindComponentByClass<UPawnCombatComponent>();

}

UWarriorAbilitySystemComponent* UWarriorGameplayAbility::GetWarriorAbilitySystemComponentFromActorInfo() const
{
	return Cast<UWarriorAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);
}
