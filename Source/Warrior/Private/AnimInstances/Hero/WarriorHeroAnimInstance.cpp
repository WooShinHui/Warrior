// Woo ShinHui All Rights Reserved

#include "AnimInstances/Hero/WarriorHeroAnimInstance.h"
#include "Characters/WarriorHeroCharacter.h"

// 플레이어에 관한 애님 인스턴스 클래스
void UWarriorHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	// 캐릭터가 있다면, 그 캐릭터는 AWarrioHeroCharacter 클래스로 캐스팅되어야 함
	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<AWarriorHeroCharacter>(OwningCharacter);
	}

}

void UWarriorHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	// 입력을 받아서 속도가 있다면 추적 시간을 0으로 바꾸고, 릴렉스 상태를 false 유지
	if (bHasAcceleration) {
		IdleElpasedTime = 0.f;
		bShouldEnterRelaxState = false;
	}
	// 그게 아니라면 추적시간은 델타 타임으로 더하고, 그 델타타임 시간이 기준시간을 넘겼다면 릴렉스 상태 돌입
	else {
		IdleElpasedTime += DeltaSeconds;

		bShouldEnterRelaxState = (IdleElpasedTime >= EnterRelaxStateThreshold);
	}
}
