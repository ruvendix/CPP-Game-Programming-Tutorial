/*
 * item.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * item.cpp는 상품에 필요한 정보와 기능을 정의한 파일입니다.
 * 상품 하나가 기준이므로 상품이 하나만 있다고 생각해야 합니다.
 * 그래야 어떻게 하나씩 다룰 수 있을지 생각해낼 수 있습니다.
 * 처음부터 대량의 상품을 다루려고 하면 상황만 복잡해집니다.
 */

#include "item.h"
#include <iomanip>
#include <iostream>

// 상품을 하나 추가합니다.
// 간단하게 count_만 추가하면 됩니다.
void Item::AddOne()
{
	// 최대 개수는 99개
	if (count_ < 99)
	{
		count_++;
	}
}

// 상품을 하나 삭제합니다.
// count_가 0 이상일 때만 삭제하면 됩니다.
void Item::RemoveOne()
{
	// count_가 1일 때 하나 삭제하면
	// 0이 되므로 굳이 count_를 0으로 만들 필요는 없지만
	// 가독성을 위해서 표시해주는 것도 나쁘지는 않음
	if (count_ > 0)
	{
		count_--;
	}
}

// 상품의 모든 정보를 출력합니다.
// 실제로 게임을 할 때는 고유번호가 필요 없으므로
// 이런 메서드는 디버깅 전용 메서드가 됩니다.
void Item::ShowItemInfo()
{
	std::cout << "상품 이름     : " << name_ << std::endl;

	// 16진수 출력
	// internal로 접두사와 값을 구분하고
	// hex(16진수), showbase(0x), uppercase(대문자)로 16진수를 설정하고
	// setw(10), setfill('0')으로 나머지 자리를 채움
	std::cout << "상품 고유번호 : " << std::internal << std::hex << std::showbase
		<< std::uppercase << std::setw(10) << std::setfill('0') << code_ << std::endl;
	std::cout.flags(0x0201); // 기본 설정으로 복구

	std::cout << "상품 가격     : " << price_ << std::endl;
	std::cout << "상품 개수     : " << count_ << std::endl << std::endl;
}