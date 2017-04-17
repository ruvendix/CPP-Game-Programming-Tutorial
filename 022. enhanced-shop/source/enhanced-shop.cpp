/* 
 * enhanced-shop.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * enhanced-shop.cpp는 STL 중 list를 사용해서 상점을 만듭니다.
 * 저번과 내용은 비슷하지만 추가되는 부분이 많으므로 잘 보셔야 합니다.
 * 일단 상점은 하나가 아니라 여러 개로 운영됩니다.
 * 그리고 각 상점은 구매와 판매가 가능합니다.
 * 게이머에게 매입할 때는 기존 가격의 80%만 받고
 * 그 상품을 판매할 때는 원래 가격에 판매합니다.
 */

// std::cout의 출력을 도와주는 헤더 파일
#include <iomanip>

// 표준 입출력을 위한 C++의 헤더 파일
// using namespace std;는 이용하지 않음!
#include <iostream>

// std::list를 위한 헤더 파일
// 반드시 이 헤더 파일을 포함해야 함!
#include <list>

// std::string을 위한 헤더 파일
// string.h가 아니라 string임!
#include <string>

#include "item/item.h"
#include "shop/shop.h"
#include "player/player.h"

void InitShops(std::list<Shop> &shops);
void ShowShops(const std::list<Shop> &shops);
bool VaildShop(std::list<Shop> &shops, const std::string &shop_name, Player &player);

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	system("title 좀 더 괜찮은 상점 만들기");

	// 처음에 게이머의 이름을 입력
	std::string input_name;
	std::cout << "캐릭터의 이름을 입력하세요 : ";
	getline(std::cin, input_name);

	std::cout << "\n환영합니다! \"" << input_name << "\" 님!\n";
	std::cout << "현재 가능한 건 상점 이용뿐입니다.\n";
	std::cout << "이 내용에 동의하시면 아무 키나 눌러주세요.\n";
	system("pause");
	system("cls");

	// 정보 초기화
	Player player(input_name, 10000);
	player.AddItem(Item("나무 막대기", 10, 1, 1), true);
	player.AddItem(Item("회복약", 50, 2, 3), true);

	// 상점을 여러 개 운영하기 위한 list
	std::list<Shop> shops;
	InitShops(shops);

	bool is_done = false;
	while (is_done == false)
	{
		std::cout << "현재 이용 가능한 상점들입니다.\n";
		ShowShops(shops);

		std::cout << "원하는 상점을 입력해주세요 (quit을 입력하면 종료) : ";
		getline(std::cin, input_name);

		if (input_name == "quit")
		{
			is_done = true;
		}
		else
		{
			// 유효한 상점인지 확인
			if (VaildShop(shops, input_name, player) == false)
			{
				std::cout << "잘못 입력했습니다!\n";
			}
			system("pause");
			system("cls");
		}
	}

	shops.clear();

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}

// 상점 및 상품 초기화
void InitShops(std::list<Shop> &shops)
{
	shops.push_back(Shop("잡화점", 2000));
	shops.back().AddItem(Item("만화책", 500, 3, 1), true);
	shops.back().AddItem(Item("좋은 회복약", 200, 4, 10), true);
	shops.back().AddItem(Item("풍선", 800, 5, 2), true);

	shops.push_back(Shop("무기점", 1500));
	shops.back().AddItem(Item("철검", 1000, 6, 1), true);
	shops.back().AddItem(Item("루비검", 1500, 7, 1), true);
	shops.back().AddItem(Item("크리스탈검", 2500, 8, 1), true);
	shops.back().AddItem(Item("다이아몬드검", 200000000, 9, 1), true);

	shops.push_back(Shop("음식점", 1000));
	shops.back().AddItem(Item("볼로네제 파스타", 500, 10, 10), true);
	shops.back().AddItem(Item("랍스터", 2000, 11, 10), true);
	shops.back().AddItem(Item("라면", 50, 12, 10), true);
	shops.back().AddItem(Item("돈까스", 80, 13, 10), true);
	shops.back().AddItem(Item("볶음밥", 70, 14, 10), true);
}

// 모든 상점 출력
void ShowShops(const std::list<Shop> &shops)
{
	int num = 1;
	for (std::list<Shop>::const_iterator i = shops.begin(); i != shops.end(); ++i, ++num)
	{
		std::cout << num << ". " << (*i).get_name() << std::endl;
	}
	std::cout << std::endl;
}

// 유효한 상점인지 확인
bool VaildShop(std::list<Shop> &shops, const std::string &shop_name, Player &player)
{
	for (std::list<Shop>::iterator i = shops.begin(); i != shops.end(); ++i)
	{
		if ((*i).get_name() == shop_name)
		{
			// 유효한 상점이면 상점에 들어감
			(*i).IntoShop(player);
			return true;
		}
	}
	return false;
}