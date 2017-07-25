/*
 * 파일 이름 : main.cpp
 * 만든 날짜 : 2017-07-25
 * 만든 사람 : Ruvendix
 *
 * 파일 설명 : static 필드와 static 메서드를 테스트합니다.
 */

#include <iostream>

#define PRESS_ENTER() printf("계속 진행하려면 엔터를 누르세요.\n"); getchar();

#include "manger/IOManager.h"

int main()
{
	mgr::IOManager::AppendStringToFile("Game.log", "게임 초기화!");
	printf("최근 작업한 파일 이름 : %s\n", mgr::IOManager::GetLastFileName().c_str());

	mgr::IOManager::AppendStringToFile("Error.log", "게임 초기화 실패!");
	printf("최근 작업한 파일 이름 : %s\n", mgr::IOManager::GetLastFileName().c_str());

	mgr::IOManager::AppendStringToFile("Game.log", "게임 종료!");
	printf("최근 작업한 파일 이름 : %s\n", mgr::IOManager::GetLastFileName().c_str());

	PRESS_ENTER();

	return 0;
}