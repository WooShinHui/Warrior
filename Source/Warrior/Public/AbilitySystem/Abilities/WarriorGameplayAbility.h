// Woo ShinHui All Rights Reserved
#pragma once
#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "WarriorGameplayAbility.generated.h"

class UPawnCombatComponent;
class UWarriorAbilitySystemComponent;

UENUM(BlueprintType)
enum class EWarriorAbilityActivitionPolicy : uint8
{
	OnTriggered,	// 입력/이벤트 등 조건 충족 시 활성화 (UGameplayAbility 기본 동작과 동일)
	OnGiven			// 어빌리티가 부여되는 즉시 자동 활성화, 1회 실행 후 자동 제거
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

	// ActorInfo : 이 어빌리티를 부여받은 액터(및 ASC)에 대한 정보
	// Spec      : 부여된 어빌리티의 실제 인스턴스 정보 (Handle, Level, IsActive 등)
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;

	// Handle              : 어빌리티 인스턴스를 구분하는 고유 ID
	// ActorInfo           : 이 어빌리티를 소유한 액터(및 ASC)에 대한 정보
	// ActivationInfo      : 이 어빌리티가 로컬 예측(Predicted)인지 서버 권위(Authoritative)인지에 대한 정보
	// bReplicateEndAbility: 어빌리티 종료 사실을 네트워크로 리플리케이션할지 여부 ( 알릴건지 말 건지)
	// bWasCancelled       : 정상 종료인지, 중간에 취소(Cancel)되었는지 여부
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	//~ End UGameplayAbility Interface.

	// OnTriggered 정책은 부모(UGameplayAbility)의 기본 Activate 방식과 동일하므로 별도 오버라이드 로직 불필요
	// (OnGiven 정책만 OnGiveAbility / EndAbility에서 자동 활성화 및 자동 제거 처리)
	UPROPERTY(EditDefaultsOnly, Category = "WarriorAbility")
	EWarriorAbilityActivitionPolicy AbilityActivationPolicy = EWarriorAbilityActivitionPolicy::OnTriggered;

	UFUNCTION(BlueprintPure,Category = "Warrior|Ability")
	UPawnCombatComponent* GetPawnCombatComponentFromActorInfo() const;

	UFUNCTION(BlueprintPure, Category= "Warrior|Ability")
	UWarriorAbilitySystemComponent* GetWarriorAbilitySystemComponentFromActorInfo() const;
};