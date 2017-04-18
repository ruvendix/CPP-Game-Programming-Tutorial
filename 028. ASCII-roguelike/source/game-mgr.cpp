/*
 * game-mgr.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * game-mgr.cpp는 GameMGR 클래스가 정의되어있습니다.
 * 게임의 4대 구조인 정보 초기화, 정보 갱신, 정보 출력, 정보 정리를 잘 보세요.
 */

// 새로 만든 헤더 파일은 include 폴더에 있음
#include "../include/game-mgr.h"

// 표준 입출력을 위한 C++의 헤더 파일
// using namespace std;는 이용하지 않음!
// cstdio도 포함되어있으므로 C 스타일의 표준 입출력도 사용 가능!
#include <iostream>

// std::string을 위한 헤더 파일
// string.h가 아니라 string임!
#include <string>

// 게임 정보 초기화
bool GameMGR::Init()
{
	// 게이머 초기화
	Player player(0, 0, 100, 10, 5, 0, '@');
	player_ = player;

	printf("게임을 초기화했습니다!\n\n");
	return true;
}

// 게임 정보 갱신
int GameMGR::Update()
{
	char input;
	printf("q를 입력하면 게임이 종료됩니다 : ");
	scanf("%c", &input);
	std::cin.ignore(); // 입력 버퍼에 남아있는 문자 삭제

	// q를 입력하면 게임 종료
	if (input == tolower('q'))
	{
		printf("\n");
		return 1;
	}

	printf("게임 정보를 갱신했습니다!\n");
	return 0;
}

// 게임 정보 출력
void GameMGR::Show()
{
	printf("----------------------------\n");
	player_.get_info().ShowUnitInfo();
	printf("----------------------------\n");
	printf("게임 정보를 출력했습니다!\n\n");
}

// 게임 정보 정리
void GameMGR::Release()
{
	printf("게임 정보를 정리했습니다!\n");
}