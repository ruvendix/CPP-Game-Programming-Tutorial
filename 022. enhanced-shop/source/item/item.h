/* 
 * item.h
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * item.h는 상품에 필요한 정보와 기능을 선언한 파일입니다.
 * 접근 함수는 인라인 형식으로 정의되어있으니 참고하세요.
 */

#ifndef ENHANCEDSHOP_ITEM_ITEM_H
#define ENHANCEDSHOP_ITEM_ITEM_H

#include <string>

class Item
{
public:
	// 기본 생성자
	// 구성원 초기화(멤버 이니셜라이저)로 기본값 설정
	Item() : name_("이름 없음"), price_(0), code_(0xFFFFFFFF), count_(0) {}
	
	// 오버로딩된 생성자
	Item(const std::string &name, int price, int code, int count)
		: name_(name), price_(price), code_(code), count_(count)
	{
		// 상품의 개수가 0개 미만이면 0,
		// 99개 초과하면 99개로 설정
		if (count < 0)
		{
			count_ = 0;
		}
		else if (count > 99)
		{
			count_ = 99;
		}
	}

	// 오버로딩된 생성자
	Item(const std::string &name) : name_(name) {}

	// 상품을 하나 추가
	void AddOne();

	// 상품을 하나 삭제
	void RemoveOne();

	// 디버깅 전용 출력
	void ShowItemInfo();

	// get 메서드
	// const 객체도 사용할 수 있도록 const를 붙임
	std::string get_name() const { return name_; }
	int get_code() const { return code_; }
	int get_price() const { return price_; }
	int get_count() const { return count_; }

	// set 메서드
	void set_name(const std::string &name) { name_ = name; }
	void set_code(const int code) { code_ = code; }
	void set_price(const int price) { price_ = price; }
	void set_count(const int count) { count_ = count; }
protected:
private:
	std::string name_; // 상품의 이름
	int code_;         // 상품의 고유번호
	int price_;        // 상품의 가격
	int count_;        // 상품의 개수
};

#endif