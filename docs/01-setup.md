# SETUP

### TIL | 2026-07-06 | 에셋 참조 및 UE5 아키텍쳐 설계

- 세팅 및 하드 레퍼런스/소프트 레퍼런스 학습
- 기본 클래스 구조
- WarriorBaseCharacter(C++)->WarriorHeroCharacter(C++), WarriorHeroController(C++), WarriorBaseGameMode(C++)
- C++로 뼈대를 만들어두고, 해당 클래스를 상속받아 BP 생성(BP_HeroCharacter,BP_HeroController,BP_GameModes)

### 핵심

- 소프트 레퍼런스와 하드 레퍼런스의 차이는 무엇인가?

### 정리

- 하드 레퍼런스는 진입 시 로딩(강제 로딩), 소프트 레퍼런스는 런타임 로딩(필요 시점)
- 기본 아키텍처 먼저 설계하기 -> 캐릭터와 컨트롤러, 게임모드 등 기본적인 뼈대 먼저 C++로 설계 후 클래스 상속 BP 생성
- BP_GameMode에서 컨트롤러 클래스, 폰 클래스 할당

### 느낀 점

- Init시 로딩할 것인지, 런타임에서 로딩할 것인지 메모리 누수나 개발 편의성 구조 신경쓸 것.
- 구현하고 싶은 순서대로 구현하는 것이 아닌 크게 기본 아키텍쳐(상속 구조)를 먼저 구상하고 설계할 것.
