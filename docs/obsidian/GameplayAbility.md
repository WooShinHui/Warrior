 
---
# 플레이어가 실행할 스킬 또는 행동 그 자체

- GAS에서 Ability는 캐릭터가 실행할 스킬 또는 행동 그 자체를 말한다. 예를 들면 달리기, 공격, 구르기 등 모든 행동을 말한다
 ![GameplayAbililty](./images/GameplayAbility.png)
- 캐릭터에게 Ability 컴포넌트를 붙이고, 활성화된 Ability는 한 번만 주어지는 OnGiven 형태와 OnTriggered 형태로 나뉜다.
- On Given 이후 End Ability가 호출될 수 있도록 따로 커스텀. 

 ![WeaponSpawn](./images/WeaponSpawn.png)