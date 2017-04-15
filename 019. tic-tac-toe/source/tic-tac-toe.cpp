/* 
 * tic-tac-toe.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * tic-tac-toe.cpp는 틱택토 게임을 만들어봅니다.
 * 3 X 3 체커판에서 진행되는 게임이지만
 * 체커판을 표시할 수 없으므로 그냥 3 X 3 판을 이용합니다.
 * 틱택토는 쉽게 설명하면 3목입니다. 먼저 3줄을 만드는 쪽이 승리합니다.
 */

// std::cout의 출력을 도와주는 헤더 파일
#include <iomanip>

// 표준 입출력을 위한 C++의 헤더 파일
// using namespace std;는 이용하지 않음!
#include <iostream>

// std::string을 위한 헤더 파일
// string.h가 아니라 string임!
#include <string>

// 기본 경로에서 폴더를 찾아야 함!
#include "game-manager/game-manager.h"

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	system("title 틱택토 게임");
	
	// 콘솔 창 크기 강제 설정
	system("mode con: lines=25 cols=80");

	TicTacToeMgr game_mgr;

	// 게임을 종료할 건지 확인하는 변수
	bool game_end = false;

	while (game_end == false)
	{
		game_end = game_mgr.StartGame();
	}

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}