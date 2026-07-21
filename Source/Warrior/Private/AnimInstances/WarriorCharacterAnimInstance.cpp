// Woo ShinHui All Rights Reserved


#include "AnimInstances/WarriorCharacterAnimInstance.h"
#include "Characters/WarriorBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// 이 애니메이션을 가질 캐릭터를 AWarriorBaseCharcter로 캐스팅함. TrtGetPawnOwner()로 가져옴.
void UWarriorCharacterAnimInstance::NativeInitializeAnimation() 
{
	OwningCharacter = Cast<AWarriorBaseCharacter>(TryGetPawnOwner());

		if(OwningCharacter)
		{
			OwningMovementComponent = OwningCharacter->GetCharacterMovement();
		}
}

// 실시간으로 속도가 붙었는지 체크
void UWarriorCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter || !OwningMovementComponent) {
		return;
	}
	GroundSpeed = OwningCharacter->GetVelocity().Size2D(); // z축 제외 속도 체크

	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f; // 가속도 존재 체크
}
