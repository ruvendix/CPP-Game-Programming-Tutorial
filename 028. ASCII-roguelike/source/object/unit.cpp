/*
 * unit.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * unit.cpp는 Unit 클래스가 정의되어있습니다.
 * 게이머와 적의 공통 부분이 어떤 것들인지 잘 보세요.
 */

// 새로 만든 헤더 파일은 include 폴더에 있음
#include "../../include/unit.h"

#include <iostream>

void Unit::ShowUnitInfo()
{
	printf("객체 모양 : %c\n", shape_);
	printf("객체 위치 : (%d, %d)\n", pos_.get_x(), pos_.get_y());
	printf("생명력    : %-4d\n", life_);
	printf("공격력    : %-4d\n", atk_);
	printf("방어력    : %-4d\n", def_);
	printf("경험치    : %-4d\n", exp_);
}