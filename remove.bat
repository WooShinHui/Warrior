@echo off
setlocal

:: 1. .uproject 확인 (안전장치)
if not exist "*.uproject" exit

:: 2. 실행 중인 언리얼 에디터 및 빌드 툴 강제 종료 (삭제 성공률 100%를 위해)
taskkill /f /im UnrealEditor.exe /t 2>nul
taskkill /f /im MSBuild.exe /t 2>nul

:: 3. 조용히 삭제 (rd /s /q 사용)
if exist "Binaries" rd /s /q "Binaries"
if exist "Intermediate" rd /s /q "Intermediate"
if exist "DerivedDataCache" rd /s /q "DerivedDataCache"

:: 4. 창 즉시 종료
exit