
---

## 플레이어 캐릭터 애님 인스턴스

- HeroAnimInstance가 할당될 캐릭터 (AWarriorHeroChracter) 가져오기
- 캐릭터가 현재 릴렉스 상태인지 확인하는 bool 선언 (bShouldEnterRelaxState)
- 입력을 받지 않은 최대 시간 (EnterRelaxStatethreshold)
- idle 시간 추적
- Super::NativeInitializeAnmation()을 통해 부모 클래스의 애니메이션 그대로 사용
- OwningCharacter는 AWarriorHeroCharacter로 할당
- Super::NativeThreadSafeUpdateAnimation()도 그대로 사용
- 현재 입력받은 속도가 있다면 추적 시간 0, 릴렉스 상태 false 유지 
- 없다면 추적 시간을 델타 타임으로 더하고, 델타 타임을 지났다면 릴렉스 상태 돌입

![[RelaxState 1.png]]