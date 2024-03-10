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

## GCC에서 C++17 설정

GCC 컴파일러를 사용하여 C++17 표준으로 코드를 컴파일하는 방법은 다음과 같습니다.

1. **컴파일 명령어 사용:** 소스 코드 파일을 컴파일할 때, `g++` 명령어에 `-std=c++17` 옵션을 추가합니다. 예를 들어, `g++ -std=c++17 your_file.cpp` 명령어를 사용합니다.
2. **링크 옵션 추가:** 필요한 경우, 추가적인 링크 옵션을 포함시킬 수 있습니다. 예를 들어, `g++ -std=c++17 your_file.cpp -o your_program` 명령어를 통해 실행 파일을 생성합니다.

이 방법을 통해 GCC를 사용하여 C++17 표준을 지원하는 코드를 컴파일할 수 있습니다.



# C++17의 새로운 기능

C++17은 여러 가지 새로운 기능과 개선사항을 도입했습니다. 이 문서는 C++17에서 추가된 주요 기능들에 대해 설명하고 간단한 코드 예시를 제공합니다.

## 구조화된 바인딩 (Structured Bindings)

구조화된 바인딩을 통해 튜플이나 구조체에서 직접 변수를 바인딩할 수 있게 되었습니다.

```cpp
#include <map>
#include <string>
#include <iostream>

int main() {
    std::map<std::string, int> ageMap = {{"Alice", 30}, {"Bob", 25}};

    // 구조화된 바인딩을 사용하여 map의 key와 value를 각각 name과 age 변수에 바인딩
    for (const auto& [name, age] : ageMap) {
        std::cout << name << " is " << age << " years old.\n";
    }

    return 0;
}
```
## std::optional
std::optional은 값이 없을 수 있는 상황을 나타내는 데 사용됩니다. 값이 없는 상태를 명시적으로 처리할 수 있으며, 기존의 접근 방식(예: 포인터 사용)보다 안전합니다.

```cpp
#include <iostream>
#include <optional>

std::optional<int> getOptionalValue(bool condition) {
    if (condition) {
        // 조건이 참이면 값을 가진 optional을 반환
        return 5;
    } else {
        // 조건이 거짓이면 비어있는 optional을 반환
        return {};
    }
}

int main() {
    auto value = getOptionalValue(true);
    // optional이 값을 가지고 있는지 확인
    if (value) {
        std::cout << "Value is " << *value << ".\n";
    } else {
        std::cout << "Value is not present.\n";
    }

    return 0;
}

```

## 인라인 변수(Inline Variables)
인라인 변수를 사용하면 헤더 파일에 정의된 변수가 중복 정의되는 문제를 방지할 수 있습니다. 특히 싱글톤 패턴이나 글로벌 변수에서 유용하게 사용됩니다.
```cpp
// header.h 파일에 인라인 변수를 정의
inline constexpr int MaxSize = 100;

// main.cpp
#include <iostream>
#include "header.h"

int main() {
    // 인라인 변수 MaxSize 사용
    std::cout << "MaxSize is " << MaxSize << ".\n";
    return 0;
}


```
