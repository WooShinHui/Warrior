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

![[/images/DataAssets.png]]