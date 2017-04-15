/*
 * char_string.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * char_string.cpp는 기본 자료형인 char와 표준 라이브러리 std::string을 다룹니다.
 * 앞으로 문자는 char를 이용하고, 문자열은 std::string을 이용하겠습니다.
 *
 */

// 표준 입출력을 위한 C++의 헤더 파일
// using namespace std;는 이용하지 않음!
// 당분간은 printf() 대신 std::cout을 사용하겠음!
#include <iostream>

// std::string을 위한 헤더 파일
// string.h가 아니라 string임!
#include <string>

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	// 문자를 다룰 때는 char!
	// char는 문자 하나를 저장할 수 있음!
	// 문자를 표시할 때는 ' '을 써야 함!
	char alphabet = 'B';

	std::cout << "알파벳 : " << alphabet << std::endl << std::endl;

	// 하지만 이렇게 여러 문자(문자열)를 다룰 수는 없음!
	// 여러 문자를 다루려면 char가 아니라 다른 방법이 필요함!
	// 이렇게 여러 문자를 저장하면 맨 오른쪽에 있는 문자 하나만 저장됨!
	char dog_name = 'Ben';

	std::cout << "개 이름 : " << dog_name << std::endl << std::endl;

	// 문자열을 다룰 때는 std::string!
	// std::string은 기본 자료형이 아님!
	// 문자열을 편하게 쓰라고 만든 std::cout 같은 존재!
	// 문자열을 표시할 때는 " "을 써야 함!
	std::string player_name = "Ben";

	std::cout << "유저의 닉네임은 " << player_name << "입니다." << std::endl;

	// std::string에는 수많은 기능이 있음!
	// length()는 문자열의 길이를 알려줌!
	std::cout << "닉네임은 " << player_name.length() << "개의 문자로 되어있습니다."
		<< std::endl << std::endl;

	// std::string은 이렇게 문자열 교체도 가능!
	player_name = "루벤딕스";

	std::cout << "유저의 닉네임은 " << player_name << "입니다." << std::endl;
	std::cout << "닉네임은 " << player_name.length() << "개의 문자로 되어있습니다." << std::endl;

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}