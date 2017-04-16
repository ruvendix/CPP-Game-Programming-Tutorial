/*
 * shop.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * shop.cpp는 상점에 필요한 정보와 기능을 정의한 파일입니다.
 * 상점은 상품을 여러 개 갖고 있어야 하므로 자료구조가 필요합니다.
 * 상점에서 상품이 다 바닥나면 그 상품은 목록에서 삭제됩니다.
 */

#include "shop.h"
#include <iomanip>
#include <iostream>

// list를 검색해서 상품을 추가
// 이미 있는 상품이면 개수를 추가
void Shop::AddItem(const Item &item, bool is_first /* = false */)
{
	// iterator의 약자가 i
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		// 연산자 우선순위로 인해 괄호를 쳐야 함
		// 기존의 상품을 찾은 경우
		if ((*i).get_name() == item.get_name())
		{
			(*i).AddOne();
			return;
		}
	}

	// 상품을 못 찾으면 새로 추가
	item_list_.push_back(item);

	if (is_first == false)
	{
		// 초기화 상품이 아니고 새로 추가되는
		// 상품이라면 개수를 1로 설정
		item_list_.back().set_count(1);
	}

	// 상품이 추가되면 상품의 이름이
	// 최대 길이인지 확인
	CheckMaxNameLength();
}

// 상품의 이름이 최대 길이인지 판정
void Shop::CheckMaxNameLength()
{
	int length;
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		length = (*i).get_name().size();
		if (length > max_name_length_)
		{
			max_name_length_ = length;
		}
	}
}

// list를 검색해서 상품을 삭제
// 상품의 개수가 0개면 상품을 목록에서 삭제
bool Shop::RemoveOneItem(const std::string &item_name)
{
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		if ((*i).get_name() == item_name)
		{
			// 상품을 찾으면 무조건 하나 삭제
			(*i).RemoveOne();

			if ((*i).get_count() <= 0)
			{
				item_list_.erase(i);
				return true;
			}
		}
	}
	return false;
}

// 상점 진입
void Shop::IntoShop(Player &player)
{
	bool is_done = false;
	char input;

	while (is_done == false)
	{
		ShowShop();
		player.ShowPlayer();

		std::cout << "자~ 하고 싶은 게 뭐니? (나가기 q, 구매 b, 판매 s) : ";
		std::cin >> input;
		std::cout << std::endl;

		if (input == tolower('q'))
		{
			std::cout << "잘 가렴~ 다음에 또 와~\n";
			std::cin.ignore();
			is_done = true;
		}
		else
		{
			if (input == tolower('b'))
			{
				SellItem(player);
			}
			else if (input == tolower('s'))
			{
				BuyItem(player);
			}
			system("pause");
			system("cls");
		}
	}
}

// 상품을 가져옴
void Shop::GetItem(const std::string &item_name, Item &item)
{
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		if ((*i).get_name() == item_name)
		{
			item = *i;
		}
	}
}

// 상점에서 판매
bool Shop::SellItem(Player &player)
{
	std::cout << "구매할 상품을 나한테 알려줘\n";
	std::cout << " >> ";
	std::string input_name;
	std::cin.ignore();
	getline(std::cin, input_name);
	std::cout << std::endl;

	Item item;
	GetItem(input_name, item);

	if (item.get_name() == "이름 없음")
	{
		std::cout << "그런 상품은 취급하지 않아\n";
		return false;
	}

	if (player.BuyItem(item) == false)
	{
		std::cout << "돈이 " << item.get_price() - player.get_money()
			<< "만큼 부족한 것 같은데?\n";
		return false;
	}
	else
	{
		std::cout << "고마워~ 소중하게 사용해줘~\n";
		money_ += item.get_price();
		RemoveOneItem(input_name);
		return true;
	}
	return true;
}

// 상점에서 구입
bool Shop::BuyItem(Player &player)
{
	std::cout << "판매할 상품을 나한테 알려줘~ 80% 가격에 살게~\n";
	std::cout << " >> ";
	std::string input_name;
	std::cin.ignore();
	getline(std::cin, input_name);
	std::cout << std::endl;

	Item item;
	player.GetItem(input_name, item);

	if (item.get_name() == "이름 없음")
	{
		std::cout << "뭘 팔고 싶은 거야?\n";
		return false;
	}

	int price = static_cast<int>(item.get_price() * 0.8);
	std::cout << input_name << "의 할인된 가격 : " << price << std::endl;

	if (money_ >= price)
	{
		// 판매는 80% 가격으로 판매
		AddItem(item);
		player.SellItem(input_name, price);
		money_ -= price;
		std::cout << "고마워~ 잘 사용할게~\n";
		return true;
	}
	else
	{
		std::cout << "미안하지만, 돈이 " << price - money_
			<< "만큼 부족해서 구입할 수가 없어...\n";
		return false;
	}
	return true;
}

// 상점의 정보를 출력
void Shop::ShowShop()
{
	std::cout << "--------------------------------------------\n";
	std::cout << "※" << name_ << "※\n";
	std::cout << "우리 상점에 잘 왔어~\n";
	std::cout << "상점 자본 : " << money_ << std::endl << std::endl;
	ShowItemList();
	std::cout << "--------------------------------------------\n";
}

// list를 검색해서 상품을 출력
void Shop::ShowItemList()
{
	int num = 1;
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i, ++num)
	{
		std::cout << num << ". " << std::setw(max_name_length_) << std::left
			<< (*i).get_name() << " x " << std::setw(3) << (*i).get_count()
			<< "| 값 : " << (*i).get_price() << "\n";
	}
}
