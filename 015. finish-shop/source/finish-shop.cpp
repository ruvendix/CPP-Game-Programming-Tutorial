/* 
 * finish-shop.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * finish-shop.cpp는 상점을 완성합니다.
 * 이번에는 constexpr을 사용하는데 함수에 constexpr이 붙는 건
 * C++14 이상부터 가능하므로 이 점을 주의해야 합니다.
 */

// std::cout의 출력을 도와주는 헤더 파일
#include <iomanip>

// 표준 입출력을 위한 C++의 헤더 파일
// using namespace std;는 이용하지 않음!
#include <iostream>

// std::string을 위한 헤더 파일
// string.h가 아니라 string임!
#include <string>

// constexpr 함수는 정의까지 해야 함!
// constexpr은 컴파일 타임에 상수를 사용하겠다는 것
// 따라서 배열의 크기를 설정할 때 이용할 수 있음!
constexpr int GetMaxCount()
{
	return 6;
}

// 전역 상수
// static을 붙이면 현재 소스 파일 안에서만 사용 가능!
// static const int item_count = 6; 이것을 사용할 이유가 없음
static const std::string item_list[GetMaxCount()] = {"검", "방패", "폭탄", "회복약", "주먹밥", "다이아몬드"};

// 상품의 가격도 이렇게 배열로 표현하면 switch ~ case를 사용할 필요가 없음
static const int item_price[GetMaxCount()] = {10000, 5000, 3000, 1000, 2000, 200000000};

// 함수의 원형 전방 선언
void IntoShop(int player_inventory[], int player_money);
void ShowItemList();
void ShowPlayerInventory(const int player_inventory[]);
bool BuyItem(int player_inventory[], int &player_money);

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	system("title 상점 만들기");

	// 게이머의 인벤토리
	// 상점에 있는 상품과 순서가 일치!
	// 따라서 가지고 있는 상품의 수를 그대로 쓰면 됨!
	int player_inventory[GetMaxCount()] = {1, 0, 0, 1, 3, 0};
	int player_money = 50000;

	// 게이머에게 인벤토리가 생겼으므로
	// IntoShop()도 변화가 생겨야 함!
	IntoShop(player_inventory, player_money);

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}

void IntoShop(int player_inventory[], int player_money)
{
	std::cout << "여어~ 우리 가게에 잘 왔다~\n";
	std::cout << "필요한 게 있으면 한번 골라보라고!\n\n";

	bool is_done = false;

	// is_done이 true가 아닐 때까지 반복
	while (is_done == false)
	{
		std::cout << "현재 가진 돈 : " << player_money << std::endl;
		ShowItemList();
		ShowPlayerInventory(player_inventory);
		is_done = BuyItem(player_inventory, player_money);

		// is_done은 위에서 결정되므로
		// true로 바뀌면 더 이상 화면을 지울 필요가 없음!
		if (is_done == false)
		{
			system("pause");
			system("cls");
		}
	}

	std::cout << "잘 가라~ 다음에 또 와~\n";
}

void ShowItemList()
{
	std::cout << "----------- 상품 목록 -----------\n";
	for (int i = 0; i < GetMaxCount(); ++i)
	{
		std::cout << i + 1 << ". " <<item_list[i] << 
			"(" << item_price[i] << ")" << std::endl;
	}
	std::cout << "---------------------------------\n";
}

void ShowPlayerInventory(const int player_inventory[])
{
	std::cout << "<현재 가지고 있는 아이템>\n";
	for (int i = 0; i < GetMaxCount(); ++i)
	{
		// 개수가 1개 이상일 때만 출력!
		if (player_inventory[i] > 0)
		{
			std::cout << std::setw(6) << std::left <<  item_list[i] << " x "
				<< player_inventory[i] << std::endl;
		}
	}
	std::cout << std::endl;
}

bool BuyItem(int player_inventory[], int &player_money)
{
	int input;
	std::cout << "구입할 상품은? (1 ~ " << GetMaxCount() << ", 취소는 -1) : ";
	std::cin >> input;

	if (input == -1) return true;
	
	// 입력 오류 검사
	if (input - 1 < 0 ||
		input > GetMaxCount())
	{
		std::cout << "잘못된 입력입니다!\n";
		return false;
	}

	// 게이머의 인벤토리에 상품 추가
	// 현재 가진 돈이 선택한 상품의 가격보다 많을 때만 구입
	if (player_money >= item_price[input - 1])
	{
		player_money -= item_price[input - 1];
		player_inventory[input - 1]++;
		std::cout << item_list[input - 1] << "을(를) 구입했다!\n";
	}
	else
	{
		// 부족한 금액은 (상품 가격 - 현재 가진 돈)
		std::cout << "금액이 " << item_price[input - 1] - player_money << "만큼 부족합니다!\n";
	}
	return false;
}