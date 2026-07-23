[WarriorBaseAnimInstances]
[WarriorHeroCharacter]
[AbilitySystem]

---

### 캐릭터의 뼈대가 되는 BaseCharacter 클래스

- 캐릭터의 기본 요소 (움직임, 스폰, 죽음 등의 상태)를 결정하는 클래스
- 이 클래스를 상속받아 HeroCharacter 클래스를 생성

## GAS 시스템의 메인 허브

- 모든 캐릭터의 근본이 되는 BaseCharacter가 AttributeSet, AbilitySystemComponent(ASC)를 소유해야 함
- `IAbilitySystemInterface`-> GAS를 포함하는가?
- GetAbilitySystemComponent -> WarriorAbilitySystemComponent 포인터를 넘겨줌
- 생성자 함수에서 ASC와 AttributeSet을 할당
- Character에게 컴포넌트 부착 완료
- PossessedBy란? APawn 클래스에 정의된 가상함수이며, 게임이 실행되는 순간 이 BaseCharacter를 기반으로 하는 모든 캐릭터들은 InitAbilityActorInfo(this,this)를 호출받게 됨. 첫 번째 인자는 현재 능력의 소유 주체, 두 번째 인자는 시각적 몸체
> 생성자가 아닌 곳에서 하는 이유 : Controller가 설정된 이후에 할당되어야 PossessedBy가 안전하게 연동 가능
- FORCELINE은 GetWarriorAbilitySystemComponent가 호출될 때 그 자리에 그냥 코드를 박아 넣는 최적화 키워드



