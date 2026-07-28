 
---
# 플레이어가 실행할 스킬 또는 행동 그 자체

- GAS에서 Ability는 캐릭터가 실행할 스킬 또는 행동 그 자체를 말한다. 예를 들면 달리기, 공격, 구르기 등 모든 행동을 말한다
 ![GameplayAbililty](./images/GameplayAbility.png)
- 캐릭터에게 Ability 컴포넌트를 붙이고, 활성화된 Ability는 한 번만 주어지는 OnGiven 형태와 OnTriggered 형태로 나뉜다.
- On Given 이후 End Ability가 호출될 수 있도록 따로 커스텀. 

 ![WeaponSpawn](./images/WeaponSpawn.png)


---

무기 스폰은 다음과 같은 클래스 구조를 갖는다

![WeaponClass](./images/WeaponClass.png)

데미지를 관리할 WeaponBase -> 플레이어에게 종속될 HeroWeapon 클래스

- WarriorWeaponBase에서는 UStaiticMeshComponent로 메시 & 히트박스인 UBoxComponent 클래스를 가져온다.
- 생성자 함수에서는 위 두 가지 컴포넌트를 생성하며, 충돌 가능한 WeaponCollisionBox를 만든다. 
![WeaponBase](./images/WeaponBase.png)

> 위 클래스를 바탕으로 WarriorHeroWeapon의 하위 클래스 블루프린트를 만든다. 그리고 그 블루프린트의 하위 블루프린트 클래스인 Bp_Axe를 하나 더 생성한다. why? 왜 C++ 클래스에서 한번 더 블루프린트 자식을 생성하는가?

### **C++ BP 2단 상속**

C++ 최상위 부모
- 적/NPC/플레이어 구분 없이 모든 무기의 기능
- 충돌 처리 매커니즘, 메시 컴포넌트

C++ 자식 클래스
- 플레이어 무기의 전용 기능. GAS, Socket 등

BP 최상위 부모
- 플레이어 무기의 공통 템플릿
- 무기 전체가 공유하는 트랜스폼, 사운드 등

BP 자식 클래스
- Axe 전용 메시, 콜리전 박스 크기 등 설정

---

### **블루프린트 적용** (GA_Shared_SpawnWeapon)

![bp_weapon](./images/bp_weapon.png)

- Class는 C++의 최상위 부모인 WarriorWeaponBase로 지정
- Get Avatar Actor from Actor info를 통해 소유자 정보 가져오고, 소유자의 액터를 형변환하여 가해자로 설정

![bg_weapon_2](./images/bg_weapon_2.png)

- SpawnActor가 유효하다면, 해당 액터에 컴포넌트 부착
- 캐릭터의 스켈레탈 메시 컴포넌트 추출하여 해당 컴포넌트 부착
- 무기가 붙을 캐릭터의 소켓 명칭
- Snap To Target ->소켓에 맞춤, 회전/스케일 유지
- 위 작업 완료 후 로직 종료

### **GA_Shared_SpawnWeapon의 자식 BP 생성** (GA_Hero_SpawnAxe)

![bg_weapon_3](./images/bg_weapon_3.png)

- 위 블루프린트에서 클래스 변수와 소켓 변수를 따로 파두었기 때문에 할당 가능
- 이후에는 BP_HeroCharacter에서 소켓 할당
