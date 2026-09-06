# ⚔️ GAS Warrior — UE5 Action RPG Combat System

> Unreal Engine 5 + Gameplay Ability System(GAS) 기반 소울라이크 전투 시스템 학습 프로젝트

## 📽 데모 영상

![시연 영상](docs/images/thumbnail.png)(https://www.youtube.com/watch?v=w0JdObCyL9g)

## 🛠 기술 스택

| 구분        | 스택                                             |
| ----------- | ------------------------------------------------ |
| Engine      | Unreal Engine 5.5.4                              |
| Language    | C++                                              |
| Core System | Gameplay Ability System (GAS)                    |
| Animation   | AnimBlueprint · AnimLayer · Montage · BlendSpace |

## 🎯 프로젝트 배경

이전에 C++과 AI 도움만으로 소울라이크 프로토타입을 독학 제작한 경험이 있습니다. HP/스태미너, 3단 콤보, 적 AI 추적, NavMesh 등 기본 전투를 구현했지만, **기능이 늘어날수록 코드 구조의 한계**를 체감했습니다.

- 스킬/버프/디버프를 추가할 때마다 하드코딩이 쌓임
- 능력 발동 조건, 쿨다운, 스탯 변경이 전부 개별 로직으로 흩어짐
- "이걸 구조적으로 관리하는 방법이 있을 텐데" → **GAS의 존재를 알게 됨**

이 프로젝트는 GAS의 설계 패턴(GA → GE → AttributeSet → GameplayTag)을 체계적으로 학습하며, **실제 소울라이크 전투 시스템에 적용하는 과정**을 기록한 것입니다.

## ✅ 현재 구현 상태

> Section 4 / 10 진행 중 (2026.09.06 기준)

| 기능               | 상태    | 설명                                                      |
| ------------------ | ------- | --------------------------------------------------------- |
| 무기 장착 / 해제   | ✅ 구현 | GameplayTag로 장착 상태 관리                              |
| 약공격 콤보        | ✅ 구현 | InputTag → ASC → GA → Montage 흐름, 입력 윈도우 기반 연계 |
| 강공격             | ✅ 구현 | 별도 GA + Montage, 약공격과 분기 처리                     |
| 타격 슬로우모션    | ✅ 구현 | 히트 시 시간 감속 (타격감 강화)                           |
| 공격 사운드        | ✅ 구현 | SoundCue 연동                                             |
| 적 캐릭터 세팅     | ✅ 구현 | DataAsset 기반 StartUpData로 초기화                       |
| AnimLayer 분리     | ✅ 구현 | 상체(UpperBody) / 하체 독립 애니메이션                    |
| 히트 판정 / 데미지 | 🔜 예정 | GA → GE → AttributeSet 연결                               |
| 방향성 회피        | 🔜 예정 |                                                           |
| 막기 / 패링        | 🔜 예정 |                                                           |
| 타겟 락온          | 🔜 예정 |                                                           |
| 적 AI (BT + EQS)   | 🔜 예정 |                                                           |

## 🏗 아키텍처

### GAS 파이프라인

![GAS 파이프라인](docs/images/architecture_gas_pipeline.png)

### 클래스 구조

![클래스 구조](docs/images/architecture_class_tree.png)

### 콤보 시스템 흐름

![콤보 흐름](docs/images/architecture_combo_flow.png)

## 📁 프로젝트 구조

```
Source/Warrior/
├── Characters/          # Hero, Enemy 캐릭터 클래스
├── AbilitySystem/       # ASC, AttributeSet, GA, GE
├── DataAssets/          # StartUpData (Hero/Enemy 초기화)
├── Components/          # Combat, UI 컴포넌트
├── GameplayTags/        # 태그 정의 및 관리
├── AnimInstances/       # ABP, AnimLayer
└── Types/               # 구조체 (FWarriorHeroActionData 등)

```

## 📖 개발 기록

개발 과정 및 학습 기록 → `/docs`

| 문서            | 내용               |
| --------------- | ------------------ |
| 01-setup.md     | 프로젝트 초기 세팅 |
| 02-Character.md | 캐릭터 구조 설계   |

## 🔗 관련 링크

|               |                                                        |
| ------------- | ------------------------------------------------------ |
| 📄 포트폴리오 | [PDF 링크]                                             |
| 📧 연락처     | [ewew3069@gmail.com](mailto:ewew3069@gmail.com)        |
| 🐙 GitHub     | [github.com/WooShinHui](https://github.com/WooShinHui) |
