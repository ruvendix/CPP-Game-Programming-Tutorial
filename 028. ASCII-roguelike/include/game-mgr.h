/*
 * game-mgr.h
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * game-mgr.h는 GameMGR 클래스가 선언되어있습니다.
 * 인라인 형식도 있으므로 참고하시길 바랍니다.
 */

#ifndef ASCIIROGUELIKE_GAMEMGR_H_
#define ASCIIROGUELIKE_GAMEMGR_H_

#include "player.h"

class GameMGR
{
public:
	// 게임의 4대 구조
	bool Init();    // 정보 초기화
	int  Update();  // 정보 갱신
	void Show();    // 정보 출력
	void Release(); // 정보 정리
protected:
private:
	Player player_; // 게이머
};

#endif