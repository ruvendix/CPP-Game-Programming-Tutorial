/*
 * while-for.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * while-for.cpp는 while문과 for문을 다룹니다.
 * 둘 다 자주 사용되므로 잘 알아두세요.
 * 
 */

// std::cout의 출력을 도와주는 헤더 파일
#include <iomanip>

// 표준 입출력을 위한 C++의 헤더 파일
// using namespace std;는 이용하지 않음!
#include <iostream>

// std::string을 위한 헤더 파일
// string.h가 아니라 string임!
#include <string>

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	int i = 0; // 반복자는 주로 i, j, k

	// 조건식이 참일 때만 반복!
	while (i < 10)
	{
		std::cout << std::setw(2) << std::setfill('0') << i + 1 << "번째 반복\n";
		i++; // i = i + 1 또는 i += 1과 같음
	}
	std::cout << std::endl;

	// for문은 초깃값과 증감식을 동시에 쓸 수 있음!
	// C++에서는 반복자를 내부에서 선언하는 경우가 많음!
	for (int j = 0; j < 10; ++j)
	{
		std::cout << std::setw(2) << std::setfill('0') << j + 1 << "번째 반복\n";
	}
	std::cout << std::endl;

	// do ~ while문은 조건식에 관계없이 무조건 1번 실행!
	int k = 12;
	do 
	{
		std::cout << std::setw(2) << std::setfill('0') << k - 11 << "번째 반복\n";
	} while (k < 10);
	std::cout << std::endl;

	// 무한 반복문!
	// 조건식이 무조건 참!
	// while (true)는 무조건 true를 써야 하지만
	// for (; ;)은 이 자체가 무한 반복문을 뜻함
	// 그래서 for(; ;)을 쓰는 경우가 많음!
	// 아래에 있는 코드를 실행할 때는 조심!
	//while (true) std::cout << "아";
	//for (; ; ) std::cout << "아";
	
	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}