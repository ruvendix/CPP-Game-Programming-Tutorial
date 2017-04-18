/*
 * player.h
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * player.h는 Player 클래스가 선언되어있습니다.
 * 인라인 형식도 있으므로 참고하시길 바랍니다.
 * Player 클래스는 게이머의 입력, 이동 처리 등이 포함되어있습니다.
 * Player 클래스는 Unit 클래스를 갖고 있습니다.
 */

#ifndef ASCIIROGUELIKE_PLAYER_H_
#define ASCIIROGUELIKE_PLAYER_H_

 // 새로 만든 헤더 파일은 include 폴더에 있음
#include "unit.h"

class Player
{
public:
	Player() : info_(0, 0, 0, 0, 0, 0, '0') { }
	Player(int x, int y, int life, int atk, int def, int exp, char shape)
		: info_(x, y, life, atk, def, exp, shape) { }

	// get 메서드
	Unit get_info() const { return info_; }

protected:
private:
	Unit info_;
};

#endif