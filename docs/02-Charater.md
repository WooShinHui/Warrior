# SETUP

### TIL | 2026-07-011 | 캐릭터 생성자 설정

- 언리얼 문법
- 디버그 헬퍼 추가

- WarriorBaseCharacter 생성자 카메라 함수 설정

### 핵심

- C++에서는 데이터 직접 참조가 거의 없을 듯함. ->로 포인터 접근

### 느낀 점

- CreateDefaultSubobject<>는 만들 컴포넌트의 타입을 가져옴 ex) Array<string>
- 숫자 뒤에 f는 관례적으로 붙일 것. ex) 200.f;
- ::은 네임스페이스나 클래스에 속한 정적 멤버 접근 ex) TypeScript의 phaser.gameobject 같은
