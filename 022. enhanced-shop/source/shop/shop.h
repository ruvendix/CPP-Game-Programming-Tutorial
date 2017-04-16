/*
 * shop.h
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * shop.h는 상점에 필요한 정보와 기능을 선언한 파일입니다.
 * 접근 함수는 인라인 형식으로 정의되어있으니 참고하세요.
 */

#ifndef ENHANCEDSHOP_SHOP_SHOP_H
#define ENHANCEDSHOP_SHOP_SHOP_H

#include <list>
#include <string>
#include "../item/item.h"
#include "../player/player.h"

class Shop
{
public:
	Shop() : name_("이름 없음"), money_(0) {}
	Shop(const std::string &name, int money) : name_(name), money_(money) {}
	
	// list 정리를 위해 소멸자 사용
	~Shop() { item_list_.clear(); }

	// 상품 추가
	void AddItem(const Item &item, bool is_first = false);

	// 상품의 이름이 최대 길이인지 판정
	void CheckMaxNameLength();

	// 상품의 이름으로 상품 하나 삭제
	bool RemoveOneItem(const std::string &item_name);

	// 상점 진입
	void IntoShop(Player &player);

	// 상품 가져오기
	void GetItem(const std::string &item_name, Item &item);

	// 상점에서 판매
	bool SellItem(Player &player);

	// 상점에서 구입
	bool BuyItem(Player &player);

	// 상점 정보 출력
	void ShowShop();
	
	// 상점의 상품 목록 출력
	void ShowItemList();

	// get 메서드
	std::string get_name() const { return name_; }

	// set 메서드
	void set_name(const std::string &name) { name_ = name; }
protected:
private:
	std::list<Item> item_list_; // 상품 목록
	std::string name_;          // 상점 이름
	int money_;                 // 상점 돈
	int max_name_length_;       // 상품 이름의 최대 길이
};

#endif