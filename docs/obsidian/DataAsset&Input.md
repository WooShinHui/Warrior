[WarriorHeroCharacter]

---
## InputTag

- struct로 순수 데이터 묶음 설정
- FGamePlayTag, UInputAction 클래스 선언

## UDataAsset

- 값을 넣을 수 있는 데이터 컨테이너, UE에서 직접 클래스 선택해서 조합 가능
- UInputMappingContext 선언
- `TArray<FWarriorInputActionConfig> NativeInputActions` 선언. (TArray는 리스트보다 빠름, 인덱싱 접근 가능)
- UInputAction* FindNativeInputActionByTag(const FGamePlayTag& InInputTag) const;

---
전체적으로 인풋에 대한 Tag를 설정하고, 해당 설정들을 UE에서 설정할 수 있는 기본 틀을 잡아주는 클래스!

![DataAssets](./images/DataAssets.png)


## 무기 스폰

![GA_hero_SpawnAxe](./images/GA_hero_SpawnAxe.png)

GA(게임 어빌리티 블루프린트)를 만들고 오른쪽 상단에 BP_HeroAxe를 할당한다. TAG도 붙인다. 



## 인풋 태그와 바인딩

![abilitysystem](./images/abilitysystem.png)

WarriorAbilitySystemComponent에서 Input 눌렀을 때에 대한 처리를 한다. 이 함수는 유효하다면, 태그를 넘겨주는 역할을 하는 듯 하다.

![WarriorGameplayTag](./images/WarriorGameplayTag.png)

WarrioGameplayTags.ccp와 h에 추가해주고

![IA_EquipAxe](./images/IA_EquipAxe.png)

데이터 에셋 IA_EquipAxe를 추가해주고


![DA_inputConfig](DA_inputConfig.png)

InputConfig에서 IA_EquipAxe를 할당

![imc](./images/imc.png)

IMC_Default에서 IA_EquipAxe를 1번으로 매핑한다.