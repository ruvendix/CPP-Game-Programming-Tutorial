/*
 * loops-recap-bool.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * loops-recap-bool.cpp는 반복문 보충과 bool을 다룹니다.
 * bool은 참과 거짓을 판단할 때 사용하는 기본 자료형이므로 잘 알아두세요.
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
	for (int i = 0; i < 3; ++i)
	{
		// 반복문 안에 반복이 들어가면 중첩 반복문!
		// 반복할 횟수는 반복자의 반복 횟수를 곱하면 됨
		// i의 반복 횟수 => 3
		// j의 반복 횟수 => 4
		// 총 반복 횟수  => 3 * 4 = 12
		for (int j = 0; j < 4; ++j)
		{
			// j의 반복 횟수를 이용하면
			// 총 반복 횟수를 구할 수 있음!
			// (i * j의 반복 횟수) + j
			std::cout << std::setw(2) << std::setfill('0')
				<< (i * 4) + j + 1<< "번째 반복\n";
		}
		std::cout << std::endl;
	}

	// 2부터 1000까지 2의 제곱수 출력
	// i의 초깃값을 0으로 설정하면 무조건 0이 되므로
	// 무한 반복문이 되니까 주의!
	for (int i = 2; i < 1000; i *= 2)
	{
		std::cout << std::setw(3) << std::setfill('0')
			<< i << "\n";
	}
	std::cout << std::endl;

	// bool은 참과 거짓을 판단하는 기본 자료형!
	// 가독성을 위해 is~ 라고 이름을 지으면 더 좋음!
	bool is_game_over = false;

	while (is_game_over == false)
	{
		// 게임이 잘 작동하다가
		// 어느 순간에 게임 오버!
		is_game_over = true;
	}

	std::cout << "게임 오버입니다.\n";

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}