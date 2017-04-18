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

// 새로 만든 헤더 파일은 include 폴더에 있음
#include "../include/game-mgr.h"

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	system("title ASCII 로그라이크 게임");

	GameMGR game_mgr;

	// 게임 정보 초기화
	game_mgr.Init();

	bool is_exit = false;
	while (is_exit == false)
	{
		// 게임 정보 갱신 => 게임 종료 여부도 확인
		if (game_mgr.Update() == 0)
		{
			// 게임 정보 출력
			// 게임 정보를 갱신해야 출력 가능
			game_mgr.Show();
		}
		else
		{
			is_exit = true;
		}
	}

	// 게임 정보 정리
	game_mgr.Release();

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}