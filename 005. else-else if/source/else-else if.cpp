/*
 * else-else if.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * else-else if.cpp는 else와 else if문을 다룹니다.
 * if문 내용의 연장선이므로 가볍게 알아보겠습니다.
 * 
 */

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
	std::string player_name;
	int player_age;

	std::cout << "용사 님의 이름은 어떻게 되시나요? ";
	std::cin >> player_name;

	std::cout << "안녕하세요, \"" << player_name << "\" 용사 님\n\n";
	std::cout << "용사 님의 나이는 어떻게 되시나요? ";
	std::cin >> player_age;

	if (player_age <= 0)
	{
		std::cout << "나이가 0살 이하라고요...?\n";
	}
	else if (player_age <= 7)
	{
		std::cout << "나이가 어리시군요...\n";
	}
	else if (player_age >= 100)
	{
		std::cout << "나이가 많으시군요...\n";
	}
	else
	{
		std::cout << "\"" << player_name << "\" 용사 님의 나이는 \""
			<< player_age << "\"살이시군요!\n";
		std::cout << "이 게임을 플레이하기에 적절한 나이입니다.\n";
	}

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}