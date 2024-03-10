# C++17 설정하기

## Visual Studio에서 C++17 설정

Visual Studio에서 C++ 프로젝트를 C++17 표준으로 설정하는 방법은 다음과 같습니다.

1. **프로젝트 열기:** Visual Studio에서 C++ 프로젝트를 엽니다.
2. **프로젝트 속성 열기:** 프로젝트를 마우스 오른쪽 버튼으로 클릭하고, `속성(Properties)`을 선택합니다.
3. **C++ 언어 표준 설정:** `구성 속성(Configuration Properties)` > `C/C++` > `언어(Language)` 섹션으로 이동합니다. `C++ 언어 표준(C++ Language Standard)` 옵션을 찾아 `ISO C++17 표준(/std:c++17)`을 선택합니다.
4. **변경 사항 적용:** `확인`을 클릭하여 변경 사항을 적용합니다.


## VSCode에서 C++17 설정

VSCode에서 C++ 프로젝트를 C++17 표준으로 설정하는 방법은 다음과 같습니다.

1. **`c_cpp_properties.json` 파일 열기:** VSCode에서 C++ 프로젝트 폴더를 열고, `.vscode` 폴더 내의 `c_cpp_properties.json` 파일을 엽니다. 해당 파일이 없는 경우, `Ctrl+Shift+P`를 눌러 명령 팔레트를 열고 `C/C++: Edit Configurations (UI)`를 검색하여 실행합니다.
2. **C++ 표준 설정:** `c_cpp_properties.json` 파일에서 `C_Cpp.default.cppStandard` 속성을 찾아 `"c++17"`로 설정합니다. 예를 들어, `"cppStandard": "c++17"` 과 같이 설정합니다.
3. **파일 저장:** 변경 사항을 적용하려면 파일을 저장합니다.

이 과정을 통해 VSCode에서 C++ 프로젝트가 C++17 표준을 사용하도록 설정됩니다.
