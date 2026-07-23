  
### TIL | 2026-07-06 | 에셋 참조 및 UE5 아키텍쳐 설계

  

- 세팅 및 하드 레퍼런스/소프트 레퍼런스 학습

- 기본 클래스 구조

  

- WarriorBaseCharacter (C++)

  - WarriorHeroCharacter (C++) → BP_HeroCharacter

- WarriorHeroController (C++) → BP_HeroController

- WarriorBaseGameMode (C++) → BP_GameModes

  

>C++로 뼈대를 만들어두고, 해당 클래스를 상속받아 BP 생성(BP_HeroCharacter,BP_HeroController,BP_GameModes)

  

### 핵심

  

- 소프트 레퍼런스와 하드 레퍼런스의 차이는 무엇인가?

  

### 정리

  

- 하드 레퍼런스는 진입 시 로딩(강제 로딩), 소프트 레퍼런스는 런타임 로딩(필요 시점)

- 기본 아키텍처 먼저 설계하기 -> 캐릭터와 컨트롤러, 게임모드 등 기본적인 뼈대 먼저 C++로 설계 후 클래스 상속 BP 생성

- BP_GameMode에서 컨트롤러 클래스, 폰 클래스 할당

  

### 느낀 점

  

- Init시 로딩할 것인지, 런타임에서 로딩할 것인지에 대한 이슈 고려

- 기능 단위 즉흥 작성 대신 클래스 계층 우선 설계 습관 필요

  

### 참고 이미지

  

![BaseGameMode](./images/BaseGameMode.png)

![Character](./images/Character.png)