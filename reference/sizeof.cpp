#include <iostream>

int main() {
    // 기본 데이터 타입의 크기 출력
    std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "Size of short: " << sizeof(short) << " bytes" << std::endl;
    std::cout << "Size of long: " << sizeof(long) << " bytes" << std::endl;
    std::cout << "Size of long long: " << sizeof(long long) << " bytes" << std::endl;
    std::cout << "Size of float: " << sizeof(float) << " bytes" << std::endl;
    std::cout << "Size of double: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "Size of char: " << sizeof(char) << " bytes" << std::endl;
    std::cout << "Size of bool: " << sizeof(bool) << " bytes" << std::endl;

    // 포인터 타입의 크기 출력
    int* ptr = nullptr;
    std::cout << "Size of pointer: " << sizeof(ptr) << " bytes" << std::endl;

    // 사용자 정의 데이터 타입(구조체)의 크기 출력
    struct MyStruct {
        int i;
        double d;
        char c;
    };
    std::cout << "Size of MyStruct: " << sizeof(MyStruct) << " bytes" << std::endl;

    // 주석으로 변수 타입과 크기를 테이블 형식으로 정리
    /*
    | Variable Type | Size in 32-bit (bytes) | Size in 64-bit (bytes) |
    |---------------|------------------------|------------------------|
    | int           | 4                      | 4                      |
    | short         | 2                      | 2                      |
    | long          | 4                      | 8                      |
    | long long     | 8                      | 8                      |
    | float         | 4                      | 4                      |
    | double        | 8                      | 8                      |
    | char          | 1                      | 1                      |
    | bool          | 1                      | 1                      |
    | pointer       | 4                      | 8                      |
    | MyStruct      | 12                     | 16                     |
    */
    
    return 0;
}
