/* 
 * ASCII-roguelike.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * ASCII-roguelike.cpp는 세 번째 게임인 ASCII 로그라이크를 만들어봅니다.
 * 규모가 좀 있는 게임이지만 개발 과정을 잘 따라오면 정복할 수 있을 겁니다.
 * 게임을 완성하면 추가 콘텐츠를 넣어서 완성도를 높여보세요.
 */

// getch()를 위한 C의 헤더 파일
// 윈도우 운영체제에만 존재하므로 비표준 헤더 파일
// 문제가 생기면 SDL 검사를 "아니요"로 수정
#include <conio.h>

// 표준 입출력을 위한 C++의 헤더 파일
// using namespace std;는 이용하지 않음!
// cstdio도 포함되어있으므로 C 스타일의 표준 입출력도 사용 가능!
#include <iostream>

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	system("title ASCII 로그라이크 게임");

	printf("아무 키나 누르세요\n");
	system("pause");

	char input;
	bool is_quit = false;
	while (is_quit == false)
	{
		input = _getch(); // 키보드를 입력하면 바로 반응하는 함수
		if (input != '`')
		{
			printf("입력한 문자 : %c\n", input);
		}
		else
		{
			is_quit = true;
		}
	}

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}