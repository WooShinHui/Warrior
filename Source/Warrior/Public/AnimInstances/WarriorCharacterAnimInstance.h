// Woo ShinHui All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorBaseAnimInstances.h"
#include "WarriorCharacterAnimInstance.generated.h"

class AWarriorBaseCharacter;
class UCharacterMovementComponent;

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorCharacterAnimInstance : public UWarriorBaseAnimInstances
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override; // 애니메이션 인스턴스 초기화 캐릭터,컴포넌트 참조 바인딩
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds); // 애니메이션 최적화 (워커 스레드 병렬 실행?) NativeUpdateAnimation은 메인 스레드, 주요 API 사용불가

protected:
	UPROPERTY()
	AWarriorBaseCharacter* OwningCharacter;

	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComponent;

	UPROPERTY(VisibleDefaultsOnly,BluePrintReadOnly,Category = "AnimData|LocomotionData")
	float GroundSpeed; // z축 제외 속도 체크

	UPROPERTY(VisibleDefaultsOnly, BluePrintReadOnly, Category = "AnimData|LocomotionData")
	bool bHasAcceleration; // 가속도 여부 체크
};
