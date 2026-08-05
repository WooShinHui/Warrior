// Woo ShinHui All Rights Reserved


#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"
#include "Characters/WarriorHeroCharacter.h"
#include "Controllers/WarriorHeroController.h"

// 스마트 포인터로 캐싱된 캐릭터 접근 -> 현재 캐릭터 정보를 HeroCharacter로 캐스팅
AWarriorHeroCharacter* UWarriorHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedWarriorHeroCharacter.IsValid())
	{
		CachedWarriorHeroCharacter = Cast<AWarriorHeroCharacter>(CurrentActorInfo->AvatarActor);
	}

    return CachedWarriorHeroCharacter.IsValid() ?  CachedWarriorHeroCharacter.Get() : nullptr;
}

// 스마트 포인터로 캐싱된 컨트롤러 접근 -> 현재 캐릭터 정보를 HeroController로 캐스팅
AWarriorHeroController* UWarriorHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedWarriorHeroController.IsValid())
	{
		CachedWarriorHeroController = Cast<AWarriorHeroController>(CurrentActorInfo->PlayerController);
	}
	return CachedWarriorHeroController.IsValid()? CachedWarriorHeroController.Get() : nullptr;
}

// HeroCharacter에서 HeroCombatComponent를 가져오는 헬퍼 함수
UHeroCombatComponent* UWarriorHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}
