// Woo ShinHui All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WARRIOR_API UPawnExtensionComponentBase : public UActorComponent
{
	GENERATED_BODY()

protected:
	// 매번 GetOwner()를 호출하는 대신, GetOwner를 가져와서 캐스팅하는 헬퍼 함수
	// GetOwner가 반환하는 AActor*을 지정한 APawn 파생 클래스 타입 T*으로 캐스팅해주는 헬퍼
	// 즉, 현재 호출한 곳의 타입으로 캐스팅해주는 헬퍼
	template <class T>
	T* GetOwningPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "T must be derived from APawn");
		return CastChecked<T>(GetOwner());
	}
	// 기본적으로 APawn*을 반환 (오버로딩)
	APawn* GetOwningPawn() const
	{
		return GetOwningPawn<APawn>();
	}

	// 소유한 Pawn의 Controller를 지정한 AController 파생 클래스 타임 T*으로 캐스팅해주는 헬퍼
	template <class T>
	T* GetOwningController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "T must be derived from AController");
		return GetOwningPawn<APawn>()->GetController<T>();
	}
};
