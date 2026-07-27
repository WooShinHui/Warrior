#AbilitySystem

---
# GAS 시스템에 대한 이해

GAS(Gameplay Ability System)는 언리얼 엔진에서 공식 제공하는 프레임워크이다.

> GAS -> 캐릭터의 능력, 상태 수치, 수치로 인한 효과를 일관되게 관리해주는 시스템.

> 왜 Trouble이라고 생각하는가?

- GameplayEffect에 대한 직관적 이해 -> VFX? 게임에서 발생하는 이펙트인지?
- GameplayAbility? -> 게임 플레이 능력? 이게 플레이어와 무슨 관련이 있는지?

위 두 가지 사안이 와닿지 않았으며, 클로드는 다음과 같이 답해주었다.

GAS 없이 만들게 된다면 스파게티 코드 + 감당 어려워짐

- AbilitySystemComponent (ASC) | 캐릭터에 붙을 컴포넌트. GA/GE/Atrribute를 전부 관리
- GameplayAbility (GA) | 스킬/행동의 로직 (돌진/회복/패시브 등)
- GameplayEffect (GE) | Attribute를 변경하는 명령서 (데미지, 버프 등)
- AttributeSet | 캐릭터의 수치 데이터 묶음
- GameplayTag | GAS 전체를 관통하는 하나의 "라벨 시스템". 태그로 상태 조건을 체크한다.

> Ability는 행동 그 자체, Effect는 행동으로 인해 어떤 "영향"을 주었는지 따지는 명령서, Attribute는 스탯창, Tag는 현재 상태 정도로 생각하면 될 것 같다. (GE/GA 종속 관계는 아님) 

---
