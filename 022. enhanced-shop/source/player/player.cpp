/*
 * player.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * player.cpp는 게이머에게 필요한 정보와 기능을 정의한 파일입니다.
 * 게이머는 상점처럼 상품 목록과 돈을 갖고 있습니다.
 * 상점과 게이머가 다른 점은 게이머는 입력 기능이 있다는 겁니다.
 */

#include "player.h"
#include <iomanip>
#include <iostream>

// 상품 추가
// list를 검색해서 중복되는 이름의 상품이 발견되면
// 그 상품의 개수를 증가시키고, 새로운 상품이 발견되면 list에 넣음
void Player::AddItem(const Item &item, bool is_first /* = false */)
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
void Player::CheckMaxNameLength()
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
bool Player::RemoveOneItem(const std::string &item_name)
{
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		if ((*i).get_name() == item_name)
		{
			// 상품을 찾으면 무조건 하나 삭제
			(*i).RemoveOne();

			// 상품의 개수가 0개 이하라면
			// list에서 상품 삭제
			if ((*i).get_count() <= 0)
			{
				item_list_.erase(i);
				return true;
			}
		}
	}
	return false;
}

// 게이머의 정보 출력
void Player::ShowPlayer()
{
	std::cout << "--------------------------------------------\n";
	std::cout << "게이머의 이름 : " << name_ << std::endl;
	std::cout << "현재 가진 돈  : " << money_ << std::endl << std::endl;
	ShowItemList();
	std::cout << "--------------------------------------------\n";
}

// 게이머의 상품 정보 출력
void Player::ShowItemList()
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

// 상품 구매
// AddItem()을 이용해서 처리
bool Player::BuyItem(const Item &item)
{
	// 구매할 상품의 가격을 임시로 저장
	// item.get_price()를 계속 호출해도 되지만
	// 함수의 호출을 줄이는 방향이 오버헤드를 줄일 수 있음
	// 그런데 이 경우는 접근 함수이므로 그다지 문제는 되지 않음
	int price = item.get_price();

	// 현재 가진 돈이 더 많을 때만 상품을 구매
	if (money_ >= price)
	{
		money_ -= price;
		AddItem(item);
		return true;
	}
	else
	{
		return false;
	}
	return false;
}

// 상품 판매
void Player::SellItem(const std::string &item_name, const int price)
{
	RemoveOneItem(item_name);
	money_ += price;
}

// 상품 가져오기
// list를 검색해서 상품의 이름을 찾고,
// 상품의 이름을 찾으면 item에 저장
void Player::GetItem(const std::string &item_name, Item &item)
{
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		if ((*i).get_name() == item_name)
		{
			item = *i;
		}
	}
}