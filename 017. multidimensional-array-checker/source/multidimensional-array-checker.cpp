/* 
 * multidimensional-array-checker.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * multidimensional-array-checker.cpp는 2차원 배열로 체커판을 출력합니다.
 * 2차원 배열은 1차원 배열에 행이 추가된 개념입니다.
 * 2차원 배열은 행과 열을 이용하므로 사각형 형태가 되지만
 * 그건 논리적인 형태일 뿐이고 실제로는 그냥 1자형입니다.
 * 메모리 공간은 사각형이 아니라 1자형이라는 걸 잘 알아두세요.
 */

// std::cout의 출력을 도와주는 헤더 파일
#include <iomanip>

// 표준 입출력을 위한 C++의 헤더 파일
// using namespace std;는 이용하지 않음!
#include <iostream>

// std::string을 위한 헤더 파일
// string.h가 아니라 string임!
#include <string>

class CheckerBoard
{
public:
	void InitBoard()
	{
		// 2차원 배열은 먼저 행으로 감싸고
		// 그 다음에 열을 처리해야 함!
		for (int row = 0; row < 8; ++row)
		{
			for (int col = 0; col < 8; ++col)
			{
				// 지그재그로 출력하려면 행 + 열로 따지면 됨
				// 행 + 열은 숫자가 순차적으로 증가하기 때문!
				if ((row + col) % 2 == 0)
				{
					board_[row][col] = '*';
				}
				else
				{
					board_[row][col] = 'o';
				}
			}
		}
	}

	void PrintBoard()
	{
		for (int row = 0; row < 8; ++row)
		{
			for (int col = 0; col < 8; ++col)
			{
				std::cout << board_[row][col];
			}
			std::cout << std::endl;
		}
	}
protected:

private:
	char board_[8][8];
};

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	system("title 체커판 출력하기");

	CheckerBoard checker_board;
	checker_board.InitBoard();
	checker_board.PrintBoard();

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}