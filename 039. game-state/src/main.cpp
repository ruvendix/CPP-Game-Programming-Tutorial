/*
 * 파일 이름 : main.cpp
 * 만든 날짜 : 2017-07-26
 * 만든 사람 : Ruvendix
 *
 * 파일 설명 : 게임 상태를 테스트합니다.
 */

#include <ctime>
#include <iostream>
#include <random>

#define PRESS_ENTER() printf("계속 진행하려면 엔터를 누르세요.\n"); getchar();

// 게임 상태를 열거형으로 선언!
// C++11 이후에는 enum class를 활용!
enum class GameState : int
{
	INIT,  // 기본값은 0
	TITLE, // 이후의 값은 1씩 증가
	OPTION,
	SCENE,
	PAUSE,
	RELEASE,
	NONE,
};

// 게임 상태처럼 여러 곳에서 쓰이는 값은
// 전역 변수로 정의하는 게 편함!
// 매니저 클래스를 이용해서 호출하는 방법도 있음!
GameState g_gameState = GameState::NONE;

int GameStateCheck();

int main()
{
	std::uniform_int_distribution<int> randomIndex(0, 6);
	std::default_random_engine randomEngine;

	time_t oldTime = clock();
	time_t newTime = clock();

	// 무한 루프는 이런 식으로도 사용함!
	for ( ; ; )
	{
		newTime = clock();

		// 2초 간격으로 실행
		if (newTime - oldTime > 2000)
		{
			oldTime = newTime;

			g_gameState = static_cast<GameState>(randomIndex(randomEngine));
			GameStateCheck();
		}		
	}

	PRESS_ENTER();

	return 0;
}

int GameStateCheck()
{
	switch (g_gameState)
	{
	case GameState::INIT    : printf("게임 초기화 중입니다.\n");   break;
	case GameState::TITLE   : printf("게임 타이틀 화면입니다.\n"); break;
	case GameState::OPTION  : printf("게임 옵션 화면입니다.\n");   break;
	case GameState::SCENE   : printf("게임 장면입니다.\n");        break;
	case GameState::PAUSE   : printf("게임 정지 화면입니다.\n");   break;
	case GameState::RELEASE : printf("게임 해제 중입니다.\n");     break;
	}

	return 0;
}