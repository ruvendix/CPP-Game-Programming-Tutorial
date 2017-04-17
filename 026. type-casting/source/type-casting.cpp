/* 
 * type-casting.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * type-casting.cpp는 기본 자료형의 형변환을 알아봅니다.
 * C에서는 ()을 이용해서 형변환을 하지만
 * C++에서는 형변환의 안전성을 위해 4가지의 예약어가 있습니다.
 * 여기서는 기본 자료형의 형변환을 담당하는 static_cast만 알아볼게요.
 * 형변환을 좀 더 제대로 알아보기 위해 cout을 이용합니다.
 */

// std::cout의 출력을 도와주는 헤더 파일
#include <iomanip>

// 표준 입출력을 위한 C++의 헤더 파일
// using namespace std;는 이용하지 않음!
// cstdio도 포함되어있으므로 C 스타일의 표준 입출력도 사용 가능!
#include <iostream>

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	system("title 형변환 실험하기");

	int num1 = 4;
	int num2 = 6;

	// int / int
	std::cout << "num1 / num2 = " << num1 / num2 << std::endl << std::endl;

	// (float)(int / int)
	std::cout << "(float)(num1 / num2) = " << static_cast<float>(num1 / num2)
		<< std::endl << std::endl;

	// (float)(int) / int
	std::cout << "(float)(num1) / num2 = " << static_cast<float>(num1) / num2
		<< std::endl << std::endl;

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}