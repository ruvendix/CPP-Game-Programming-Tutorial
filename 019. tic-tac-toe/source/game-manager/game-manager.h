/*
 * game-manager.h
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * game-manager.h는 TicTacToeMgr 클래스가 선언되어있는 파일입니다.
 * 인라인 형식도 있지만 외부에서 정의하는 형식도 있습니다.
 * 틱택토 게임을 진행시킬 필드와 메서드가 있습니다.
 */

// <프로젝트 이름>_<소스 파일의 경로>_<소스 파일의 이름>
#ifndef TICTACTOE_GAMEMANAGER_GAMEMANAGER_H_
#define TICTACTOE_GAMEMANAGER_GAMEMANAGER_H_

#include <string>

class TicTacToeMgr
{
public:
	void InitBoard();
	void ShowBoard();
	void ShowInfo();
	char InputMarker(const std::string &player);
	bool StartGame();
	bool InputMarkerInBoard();
	bool CheckWinner();
	bool RestartGame();
protected:

private:
	char board_[3][3];    // 게임판으로 사용할 2차원 배열
	char player1_marker_; // 플레이어1의 표시
	char player2_marker_; // 플레이어2의 표시
	char current_player_; // 현재 플레이어의 표시
	int  turn_;           // 게임의 턴 수
};

#endif