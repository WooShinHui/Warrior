# Character

### TIL | 2026-07-11 | 캐릭터 생성자 설정

- 언리얼 문법
- 디버그 헬퍼 추가

- WarriorBaseCharacter 생성자 카메라 함수 설정

### 핵심

- C++에서는 데이터 직접 참조가 거의 없을 듯함. ->로 포인터 접근

### 느낀 점

- CreateDefaultSubobject<>는 만들 컴포넌트의 타입을 가져옴 ex) Array<string>
- 숫자 뒤에 f는 관례적으로 붙일 것. ex) 200.f;
- ::은 네임스페이스나 클래스에 속한 정적 멤버 접근 ex) TypeScript의 phaser.gameobject 같은

---

### TIL | 2026-07-12 | 게임 플레이 태그 추가 && InputConfig 추가

- MOVE와 LOOK에 대한 게임 플레이 태그 추가
- C++ 클래스(NONE)으로 생성하며, Build.cs 파일에 AddRange 안에 추가
- 인풋 태그로 설정하는 것은 타입 안정성 + 오타에 대비하는 것으로 확인

- InputConfig 설정으로 에디터 확장성 증가
- 데이터 에셋 -> InputTag에서 위에 설정한 태그로 연결

### 핵심

- 앞으로 나올 많은 키 설정을 위해 Input Config 조기 설정

### 느낀 점

- 강의 난이도가 높아진다...
- 과연 이걸 처음부터 짤 수 있을 것인가?
- 그럼에도 Input=="w"같은 무식한 방법 대신 최적화된 방법을 안 것 같아서 기분이 좋다.
- UPROPERTY에 대해서도 조금 공부가 필요할 듯.

![Character](./images/DataAssets.png)

---

### TIL | 2026-07-15 | 인풋 컴포넌트 추가 & 인풋 바인딩

- 인풋 태그와 config를 이제 컴포넌트를 만들어서 캐릭터와 바인딩했다.
- 캐릭터와 바인딩하니 입력 키나 입력에 대한 함수를 구체적인 함수를 지정하지 않고도 인풋에 따른 아웃풋이 나왔다.
- template, inline등 잘 모르는 문법들이 추가되는 중.

- Character Bp에서 상속된 변수 표시 -> CharacterData -> InputConfigDataAsset -> 기본값을 InputConfig로 바꿨더니 Input_move와 Input_look의 함수대로 캐릭터가 움직인다.

### 핵심

- "w" "a"등 키 하나하나 명령하는 대신, 인풋 태그를 통한 바인딩을 할수록 확장성 up

### 느낀 점

- 이제 인풋을 바인딩하여 캐릭터가 움직이기 시작했다
- 다음 강의부터는 가장 고대하는 애니메이션 파트가 시작된다
- 그럼에도 인풋 바인딩, 인풋 태그 등 기초 설정에 대해서 조금 더 깊게 생각할 필요가 있다
- 하루 정도는 강의를 듣지 않고, 지금까지의 강의 내용을 한번 더 정리하는 것이 좋아보임.

---

### TIL | 2026-07-21 | 애님 인스턴스 & 로코모션 추가

- WarriorBaseAnimInstance C++ 클래스를 생성하고 캐릭터용 애님 인스턴스->플레이어용 애님 인스턴스 순으로 상속
- WarriorBaseAnimInstance 에서 또다른 상속으로 WarriorHerioLinkedAnimLayer를 생성 (무기용)
- CharacterAnimInstance는 적과 플레이어 모두 사용해야하므로, 가속도 체크, 속도 체크 여부를 헤더 파일에 선언

### 핵심

- 이전에 InputComponent로 캐릭터를 움직이게 설계했기 때문에, AnimInstance에서는 속도에 따른 체크만 해주면 됨
- 속도, 상태에 따른 애니메이션만 중심적으로 설계함으로써 확장성과 캡슐화의 필요성을 정당화 함
- 속도에 따른 이동은 BlendSpace 1D로 설계
- 플레이어와 적이 공용으로 사용하는 클래스에 속도, 가속도 여부에 대한 bool값을 설정

### 느낀 점

- 인풋 태그같은 어려운 API만 보다가 많이 다뤄본 애니메이션 파트가 나오니 진도가 빨리 나감
- 인풋 컴포넌트로 속도 가속도 체크만 하면 어려운 상태 머신을 짤 필요가 없다는 느낌이 오고 있다. (물론 공격이나 구르기같은 예외 동작이 있을 때 어떻게 흘러갈지는 모르지만, 적어도 코드 어디에선가 속도체크를 항상 할 필요는 없다)
- 속도에 따른 idle->jog 움직임은 BlendSpace 1D로 처리. (이 강의만 그런 것인지는 이후 확인 필요) 락온 시 어떻게 움직임을 구현할 지 기대

![Character](./images/Locomotion.png)
![Character](./images/AnimStructure.png)
