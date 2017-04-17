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

 // 상품 추가
 // list를 검색해서 중복되는 이름의 상품이 발견되면
 // 그 상품의 개수를 증가시키고, 새로운 상품이 발견되면 list에 넣음
void Shop::AddItem(const Item &item, bool is_first /* = false */)
{
	// iterator의 약자가 i
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		// 연산자 우선순위로 인해 괄호를 쳐야 함
		// 기존의 상품을 찾은 경우
		if ((*i).get_name() == item.get_name())
		{
			(*i).AddOne(); // 기존 상품 하나 증가
			return;
		}
	}

	// 상품을 못 찾으면 새로 추가
	item_list_.push_back(item);

	// 초기화용이 아니라면
	// 새로 들어온 상품의 개수는 무조건 1개
	if (is_first == false)
	{
		item_list_.back().set_count(1);
	}

	// 깔끔하게 출력하기 위해
	// 상품의 이름이 최대 길이인지 확인
	CheckMaxNameLength();
}

// 상품의 이름이 최대 길이인지 판정
void Shop::CheckMaxNameLength()
{
	int length;
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		// list에 있는 모든 상품을 검색해서
		// 상품의 이름의 길이를 계속 갱신
		length = (*i).get_name().size();

		// 상품의 이름이 현재 설정된
		// 최대 길이보다 길다면 갱신
		if (length > max_name_length_)
		{
			max_name_length_ = length;
		}
	}
}

// 상품 삭제
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

// 상품 가져오기
// list를 검색해서 상품의 이름을 찾고,
// 상품의 이름을 찾으면 item에 저장
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

// 상점에서 판매 => 게이머의 구매
bool Shop::SellItem(Player &player)
{
	std::cout << "구매할 상품을 나한테 알려줘\n";
	std::cout << " >> ";

	// 공백을 포함한 문자열을 입력받는 방법
	// 엔터를 치면 개행 문자가 입력 버퍼에 남으므로
	// ignore()로 문자 하나만 무시하면 됨
	std::string input_name;
	std::cin.ignore();
	getline(std::cin, input_name);
	std::cout << std::endl;

	Item item;
	GetItem(input_name, item); // 상점의 상품을 찾아서 item에 대입

	// 상품의 이름이 기본 설정이라면
	// 상품을 찾지 못했다는 뜻
	if (item.get_name() == "이름 없음")
	{
		std::cout << "그런 상품은 취급하지 않아\n";
		return false;
	}

	// 게이머가 구매를 실패할 경우
	if (player.BuyItem(item) == false)
	{
		std::cout << "돈이 " << item.get_price() - player.get_money()
			<< "만큼 부족한 것 같은데?\n";
		return false;
	}
	else // 게이머가 구매를 성공한 경우
	{
		std::cout << "고마워~ 소중하게 사용해줘~\n";
		money_ += item.get_price(); // 상점의 자본 증가
		RemoveOneItem(input_name);  // 상점의 상품 하나 삭제
		return true;
	}
	return true;
}

// 상점에서 구매 => 게이머의 판매
bool Shop::BuyItem(Player &player)
{
	std::cout << "판매할 상품을 나한테 알려줘~ 80% 가격에 살게~\n";
	std::cout << " >> ";

	// 공백을 포함한 문자열을 입력받는 방법
	// 엔터를 치면 개행 문자가 입력 버퍼에 남으므로
	// ignore()로 문자 하나만 무시하면 됨
	std::string input_name;
	std::cin.ignore();
	getline(std::cin, input_name);
	std::cout << std::endl;

	Item item;
	player.GetItem(input_name, item); // 게이머의 상품을 찾아서 item에 대입

	// 상품의 이름이 기본 설정이라면
	// 상품을 찾지 못했다는 뜻
	if (item.get_name() == "이름 없음")
	{
		std::cout << "뭘 팔고 싶은 거야?\n";
		return false;
	}

	// 상점에서 게이머에게 상품을 구매할 때는
	// 기본 가격의 80%만큼만 받음
	// 즉, 20% 할인된다고 생각하면 됨
	// item.get_price() * 0.8을 좀 더 편하게
	// 사용하려고 price라는 별도의 변수를 생성
	int price = static_cast<int>(item.get_price() * 0.8);
	std::cout << input_name << "의 할인된 가격 : " << price << std::endl;

	// 상점의 자본이 상품의 가격보다 많을 경우
	if (money_ >= price)
	{
		// 판매는 80% 가격으로 판매
		AddItem(item); // 게이머가 판매한 상품을 추가
		player.SellItem(input_name, price); // 게이머의 돈 증가
		money_ -= price; // 상점의 자본 감소
		std::cout << "고마워~ 잘 사용할게~\n";
		return true;
	}
	else // 상점의 자본이 상품의 가격보다 적을 경우
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
		// 상품의 최대 길이를 이용해서 정렬한 뒤에 출력
		std::cout << num << ". " << std::setw(max_name_length_) << std::left
			<< (*i).get_name() << " x " << std::setw(3) << (*i).get_count()
			<< "| 값 : " << (*i).get_price() << "\n";
	}
}
