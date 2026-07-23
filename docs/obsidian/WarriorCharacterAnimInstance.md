[WarriorHeroAnimInstance]

---

## 적, 그리고 플레이어에게 적용될 애님 인스턴스

- NativeInitializeAnimation()에서 이 애니메이션을 가질 캐릭터를 AWarriorBaseCharacter로 캐스팅하고, TryGetPawnOwner()로 가져옴. 오버라이드
- NativeThreadSafeUpdateAnimation()에서 실시간으로 속도가 붙었는지 체크 (워커 스레드 병렬 실행용)
- GroundSpeed, bHasAcceleration 여부 체크!
- ![[/images/AnimStructure.png]]


![[/images/RelaxState.png]]