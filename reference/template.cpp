//############################################################
// | cafe       | http://cafe.naver.com/dremdelover          |
// | Q&A        | https://open.kakao.com/o/gX0WnTCf          |
// | business   | ultrasuperrok@gmail.com                    |
//############################################################
#include <iostream>
#include <string>

// 템플릿 함수 선언
// 템플릿은 타입에 독립적인 코드를 작성할 수 있게 해줍니다.
// 여기서는 두 값을 더하는 함수 템플릿을 선언합니다.
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    // 정수형 덧셈
    // add<int> 템플릿 인스턴스화: T가 int로 대체됩니다.
    int intResult = add(10, 20);
    std::cout << "Addition of integers: " << intResult << std::endl;

    // 실수형 덧셈
    // add<double> 템플릿 인스턴스화: T가 double로 대체됩니다.
    double doubleResult = add(10.5, 20.3);
    std::cout << "Addition of doubles: " << doubleResult << std::endl;

    // 문자열형 덧셈 (문자열 결합)
    // add<std::string> 템플릿 인스턴스화: T가 std::string으로 대체됩니다.
    std::string strResult = add(std::string("Hello, "), std::string("World!"));
    std::cout << "Addition of strings: " << strResult << std::endl;

    return 0;
}

/*
템플릿의 목적:
- 템플릿은 다양한 데이터 타입을 처리할 수 있는 일반화된 코드를 작성하기 위해 사용됩니다.
- 코드를 재사용할 수 있어 중복을 줄이고 유지보수성을 높입니다.

템플릿의 장점:
1. 코드 재사용성: 동일한 코드가 여러 타입에 대해 동작할 수 있습니다.
2. 타입 안정성: 컴파일 시간에 타입 검사가 이루어지므로, 런타임 에러를 줄일 수 있습니다.
3. 유연성: 함수나 클래스가 다양한 데이터 타입을 처리할 수 있도록 합니다.

템플릿의 사용방법:
1. 템플릿 선언: `template <typename T>` 또는 `template <class T>` 형식을 사용합니다.
2. 함수 또는 클래스 정의: 템플릿 파라미터 T를 사용하여 타입에 독립적인 코드를 작성합니다.
3. 템플릿 인스턴스화: 함수나 클래스를 사용할 때, 구체적인 타입을 지정하여 인스턴스화합니다.

예시:
- `add<int>(10, 20)`: 정수형 덧셈을 수행합니다.
- `add<double>(10.5, 20.3)`: 실수형 덧셈을 수행합니다.
- `add<std::string>(std::string("Hello, "), std::string("World!"))`: 문자열 결합을 수행합니다.

코드 설명:
1. 템플릿 함수 선언: `template <typename T>`를 사용하여 `T`라는 템플릿 파라미터를 선언합니다. `add` 함수는 두 개의 `T` 타입 인자를 받아 더한 값을 반환합니다.
2. 정수형 덧셈: `add(10, 20)`는 `int` 타입의 두 값을 더한 결과를 출력합니다.
3. 실수형 덧셈: `add(10.5, 20.3)`는 `double` 타입의 두 값을 더한 결과를 출력합니다.
4. 문자열형 덧셈: `add(std::string("Hello, "), std::string("World!"))`는 `std::string` 타입의 두 문자열을 결합한 결과를 출력합니다.
*/
