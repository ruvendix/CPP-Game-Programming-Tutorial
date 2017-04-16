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
void Player::AddItem(const Item &item, bool is_first /* = false */)
{
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		if ((*i).get_name() == item.get_name())
		{
			(*i).AddOne();
			return;
		}
	}

	item_list_.push_back(item);

	if (is_first == false)
	{
		item_list_.back().set_count(1);
	}
	CheckMaxNameLength();
}

// 상품의 이름이 최대 길이인지 판정
void Player::CheckMaxNameLength()
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

// 상품 삭제
bool Player::RemoveOneItem(const std::string &item_name)
{
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		if ((*i).get_name() == item_name)
		{
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
		std::cout << num << ". " << std::setw(max_name_length_) << std::left
			<< (*i).get_name() << " x " << std::setw(3) << (*i).get_count()
			<< "| 값 : " << (*i).get_price() << "\n";
	}
}

// 상품 구매
bool Player::BuyItem(const Item &item)
{
	int price = item.get_price();
	bool overlap = false;
	std::list<Item>::iterator i;

	for (i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		if ((*i).get_name() == item.get_name())
		{
			overlap = true;
			break;
		}
	}

	// 현재 가진 돈이 더 많을 때만 상품을 구매
	if (money_ >= price)
	{
		money_ -= price;

		if (overlap == true)
		{
			(*i).AddOne();
		}
		else
		{
			AddItem(item);
		}
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