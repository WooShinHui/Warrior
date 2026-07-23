[DataAsset&Input]
[WarriorHeroAnimInstance]

## 플레이어 캐릭터 클래스

- USpringArmComponent, UCameraComponent 등 카메라 관련 컴포넌트 선언 (플레이어에게 국한되기 때문)
-  UDataAsset_InputConfig 선언 (플레이어의 움직임과 시야 설정)
- 생성자 함수에서 `CreateDefaultSubObject<USpringArmComponent>`, `<UCameraComponent>` 선언 (CreateDefaultSubObjects는 생성자 함수에서만 가능) 
- CharacterMovement도 생성자 함수에서 미리 설정 (이동속도, 회전속도 등)

---
#### 인풋 컴포넌트

- checkf(InputConfigDataAsset, Text())로 인풋 태그가 있는지 검사
- 체크가 통과되면, 로컬 플레이어에 플레이어 컨트롤러 지정 `GetController<APlayerController>`
- UEnhancedInputLocalPlayerSubSystem을 로컬 플레이어에 할당
- SubSystem있는지 체크 후 매핑
- UWarriorInputComponent를 BindNativeInputAction(InputConfigDataAsset, WarriorGameplayTags::InputTag_Move, ETriggerEvent::Triggerd, this, &ThisClass::Input_Move)

#### Input_move

- InputComponent에서 바인딩된 InputActionValue의 FVector2D의 X축, Y축 속도를 검사
- 각 속도들이 0이 아니라면 AddMovementInput()

#### Input_look

-  InputComponent에서 바인딩된 InputActionValue의 Look을 검사
- 각 value가 0이 아니라면 AddControllerYaw()
