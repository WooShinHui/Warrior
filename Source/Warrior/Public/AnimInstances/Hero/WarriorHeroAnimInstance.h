// Woo ShinHui All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorCharacterAnimInstance.h"
#include "WarriorHeroAnimInstance.generated.h"

class AWarriorHeroCharacter;
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorHeroAnimInstance : public UWarriorCharacterAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override; 
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds);

protected:
	// 이 HeroAnimInstances가 할당될 캐릭터
	UPROPERTY(VisibleDefaultsOnly, BluePrintReadOnly, Category = "AnimData|References")
	AWarriorHeroCharacter* OwningHeroCharacter;

	// 현재 릴렉스 상태인지 확인하는 bool (입력받지 않고 시간이 지났는지 확인)
	UPROPERTY(VisibleDefaultsOnly, BluePrintReadOnly, Category = "AnimData|LocomotionData")
	bool bShouldEnterRelaxState;

	// 입력을 받지 않은 시간 기준
	UPROPERTY(EditDefaultsOnly, BluePrintReadOnly, Category = "AnimData|LocomotionData")
	float EnterRelaxStateThreshold = 5.f;

	// idle 시간 추적 (현재 몇초가 지났는지)
	float IdleElpasedTime;
};
