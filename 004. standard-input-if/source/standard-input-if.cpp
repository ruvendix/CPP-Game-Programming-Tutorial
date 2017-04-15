/*
 * standard-input-if.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * standard-input-if.cpp는 표준 입력과 if문을 다룹니다.
 * 표준 입력은 std::cin을 사용하는데 띄어쓰기 포함 입력은 생략하겠습니다.
 * 또 다른 선택문인 switch ~ case문은 나중에 다루겠습니다.
 * 
 */

// 표준 입출력을 위한 C++의 헤더 파일
// using namespace std;는 이용하지 않음!
// std::cin도 iostream에 포함됨!
#include <iostream>

// std::string을 위한 헤더 파일
// string.h가 아니라 string임!
#include <string>

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	std::string player_name;
	int player_age;

	std::cout << "용사 님의 이름은 어떻게 되시나요? ";
	
	// std::cin은 표준 입력을 위한 도구!
	// std::cout과 방향이 반대라는 것을 주의!
	std::cin >> player_name;

	std::cout << "안녕하세요, \"" << player_name << "\" 용사 님\n\n";
	std::cout << "용사 님의 나이는 어떻게 되시나요? ";
	std::cin >> player_age;

	std::cout << "\"" << player_name << "\" 용사 님의 나이는 \"" << player_age
		<< "\"살이시군요!" << std::endl;

	// if (조건) 이렇게 사용!
	// 조건이 참이면 작업을 처리하고
	// 조건이 거짓이면 작업을 처리하지 않음!
	// 비교 연산은 >, >=, <, <=, ==, != 이렇게 있음!
	if (player_age <= 4) std::cout << "나이가 어리시군요...\n\n";

	// 조건식을 항상 참으로 만들고 싶다면 true를,
	// 조건식을 항상 거짓으로 만들고 싶다면 false를 쓰자!
	if (true) std::cout << "조건식이 항상 참입니다.\n\n";
	
	// 조건식이 거짓일 때 !를 쓰면 거짓을 부정 => 참
	if (!false) std::cout << "조건식이 항상 거짓입니다.\n";

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}