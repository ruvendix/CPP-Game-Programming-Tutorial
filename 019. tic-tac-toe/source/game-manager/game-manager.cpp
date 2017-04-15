/*
 * game-manager.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * game-manager.cpp는 TicTacToeMgr 클래스가 정의되어있는 파일입니다.
 * TicTacToeMgr 클래스의 메서드는 이 파일에 정의되어있습니다.
 * 게임판 초기화 -> 게임 진행 -> 승리 판정의 흐름을 잘 보세요.
 */

// 소스 파일과 헤더 파일이 같은 폴더에 있으면
// 그냥 헤더 파일만 포함하면 됨
#include "game-manager.h"

#include <iostream>

// 게임 시작
bool TicTacToeMgr::StartGame()
{
	// 게임이 끝났는지 확인하는 변수
	bool game_over = false;

	InitBoard();
	player1_marker_ = InputMarker("플레이어1");
	player2_marker_ = InputMarker("플레이어2");
	
	// 무승부를 확인할 변수
	// 3 X 3으로된 판에서는 9가 최대임
	turn_ = 0;

	std::cout << "\n<틱택토 게임을 시작합니다!>\n\n";
	
	// 플레이어1이 먼저 시작
	current_player_ = player1_marker_;

	while (game_over == false)
	{
		ShowInfo();

		// 먼저 플레이어1이 입력
		InputMarkerInBoard();

		// 승리 판정하기
		if (CheckWinner() == true)
		{
			system("cls");
			ShowInfo();

			if (current_player_ == player1_marker_)
			{
				std::cout << "플레이어1의 승리!\n";
			}
			else
			{
				std::cout << "플레이어2의 승리!\n";
			}

			game_over = true;
		}
		else if (turn_ == 9)
		{
			system("cls");
			ShowInfo();

			std::cout << "무승부!\n";
			game_over = true;
		}

		if (game_over == false)
		{
			// 플레이어 변경
			if (current_player_ == player1_marker_)
			{
				current_player_ = player2_marker_;
			}
			else
			{
				current_player_ = player1_marker_;
			}

			system("pause");
			system("cls");
		}
	}

	// 게임을 다시 시작할 건지 확인함
	// main()에 있는 game_end가 false면 다시 시작!
	// game_end가 true면 게임을 종료한다는 것을 헷갈리면 안됨!
	if (RestartGame() == true)
	{
		std::cout << "게임을 다시 시작합니다!\n";
		system("pause");
		system("cls");
		return false;
	}
	else
	{
		std::cout << "게임을 종료합니다!\n";
		return true;
	}
	return false;
}

// 게임판 초기화
void TicTacToeMgr::InitBoard()
{
	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < 3; ++col)
		{
			board_[row][col] = ' ';
		}
	}
}

// 게임판 출력
void TicTacToeMgr::ShowBoard()
{
	std::cout << " |1|2|3|\n";
	for (int row = 0; row < 3; ++row)
	{
		std::cout << " -------\n";
		std::cout << row + 1 << "|";
		for (int col = 0; col < 3; ++col)
		{
			std::cout << board_[row][col] << "|";
		}
		std::cout << std::endl;
	}
	std::cout << " -------\n";
}

// 게임 정보 출력
void TicTacToeMgr::ShowInfo()
{
	std::cout << "플레이어1의 표시 : " << player1_marker_ << std::endl;
	std::cout << "플레이어2의 표시 : " << player2_marker_ << std::endl;
	std::cout << "현재 플레이어    : " << current_player_ << std::endl << std::endl;

	if (turn_ == 9)
	{
		turn_--;
	}

	std::cout << "<" << turn_ + 1 << "턴>" << std::endl;
	ShowBoard();
}

// 플레이어의 표시 입력
char TicTacToeMgr::InputMarker(const std::string &player)
{
	char marker;
	std::cout << player << "이(가) 사용할 표시를 입력하세요 : ";
	std::cin >> marker;
	return marker;
}

// 게임판에 표시 입력
bool TicTacToeMgr::InputMarkerInBoard()
{
	int row, col;

	std::cout << "행과 열을 입력하세요 : ";
	std::cin >> row >> col;

	if (row - 1 < 0 ||
		row - 1 > 2 ||
		col - 1 < 0 ||
		col - 1 > 2)
	{
		std::cout << "행과 열은 1~3까지만 가능합니다!\n";
		std::cout << "다음 플레이어에게 차례가 넘어갑니다.\n";
		return false;
	}

	// 입력할 위치가 비어있을 경우에만 가능!
	if (board_[row - 1][col - 1] == ' ')
	{
		board_[row - 1][col - 1] = current_player_;
		turn_++; // 입력이 될 때만 턴 증가!
	}
	else
	{
		std::cout << "그 자리는 입력할 수 없습니다!\n";
		std::cout << "다음 플레이어에게 차례가 넘어갑니다.\n";
		return false;
	}

	std::cout << "(" << row << ", " << col << ")에 입력했습니다.\n";
	return true;
}

// 승리 판정하기
// 승리 판정은 기준값을 찾고 근접한 값들이 기준값과 같은지 확인하면 됨
bool TicTacToeMgr::CheckWinner()
{
	// 가로 판정하기
	for (int i = 0; i < 3; ++i)
	{
		if (board_[i][0] != ' ' &&
			board_[i][0] == board_[i][1] &&
			board_[i][1] == board_[i][2])
		{
			return true;
		}
	}

	// 세로 판정하기
	for (int i = 0; i < 3; ++i)
	{
		if (board_[0][i] != ' ' &&
			board_[0][i] == board_[1][i] &&
			board_[1][i] == board_[2][i])
		{
			return true;
		}
	}

	// 왼쪽 위에서 오른쪽 아래 판정하기
	// \ 이 모양
	if (board_[0][0] != ' ' &&
		board_[0][0] == board_[1][1] &&
		board_[1][1] == board_[2][2])
	{
		return true;
	}

	// 오른쪽 위에서 왼쪽 아래 판정하기
	// / 이 모양
	if (board_[0][2] != ' ' &&
		board_[0][2] == board_[1][1] &&
		board_[1][1] == board_[2][0])
	{
		return true;
	}
	return false;
}

// 게임 다시 시작하기
bool TicTacToeMgr::RestartGame()
{
	char input;
	std::cout << "다시 시작할 건가요? (y/n) : ";
	std::cin >> input;

	if (tolower(input) == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}
