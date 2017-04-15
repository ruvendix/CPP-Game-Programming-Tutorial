/*
 * array-const.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * array-const.cpp는 배열과 상수에 대해 알아봅니다.
 * 배열은 연속된 메모리 공간으로서, 변수를 여러 개 만든다고 생각하시면 됩니다.
 * 배열의 개수를 5개로 정하면 배열의 첨자는 0, 1, 2, 3, 4가 됩니다.
 * 배열의 개수를 변수로 설정하려면 const를 이용해야 합니다.
 */

// 표준 입출력을 위한 C++의 헤더 파일
// using namespace std;는 이용하지 않음!
#include <iostream>

// std::string을 위한 헤더 파일
// string.h가 아니라 string임!
#include <string>

// 함수의 원형 전방 선언
void TestNumList();
void UseConst();
void IntoShop();
void ShowItemList(std::string item_list[], int count);

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	system("title 상점 만들기");

	//TestNumList();
	//UseConst();

	IntoShop();

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}

void IntoShop()
{
	const int item_count = 5;
	static std::string item_list[item_count] = {"검", "방패", "폭탄", "회복약", "주먹밥"};

	std::cout << "여어~ 우리 가게에 잘 왔다~\n";
	std::cout << "필요한 게 있으면 한번 골라보라고!\n\n";
	ShowItemList(item_list, item_count);
}

void ShowItemList(std::string item_list[], int count)
{
	std::cout << "----------- 상품 목록 -----------\n";
	for (int i = 0; i < count; ++i)
	{
		std::cout << "" <<item_list[i] << std::endl;
	}
	std::cout << "---------------------------------\n";
}

void TestNumList()
{
	// 배열의 크기는 5! 첨자의 개수를 의미!
	// 배열의 첨자는 0부터 시작!
	// 무조건 0은 아니고 1부터 시작하는 언어도 있음!
	int num_list[5] = {0, 1, 2, 3, 4};

	for (int i = 0; i < 5; ++i)
	{
		std::cout << "num_list[" << i << "] : " << num_list[i] << std::endl;
	}
}

void UseConst()
{
	// 배열의 크기는 변수로 설정할 수 있음!
	// 하지만 상수만 가능하므로 const를 이용해야 함!
	// C에서는 C11 이상부터 가능!
	const int count = 5;
	int num_list[count] = {0, 1, 2, 3, 4};

	for (int i = 0; i < count; ++i)
	{
		std::cout << "num_list[" << i << "] : " << num_list[i] << std::endl;
	}
}