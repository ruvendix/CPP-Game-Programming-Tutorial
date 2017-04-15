/*
 * monster.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * monster.cpp는 Monster 클래스가 정의되어있는 파일입니다.
 * Monster 클래스의 메서드는 이 파일에 정의되어있습니다.
 * 생성자와 오버로딩된 생성자를 유심히 살펴보세요.
 */

#include <iostream>

// 소스 파일과 헤더 파일이 같은 폴더에 있으면
// 그냥 헤더 파일만 포함하면 됨
#include "monster.h"

// 외부에서 메서드를 정의하려면
// (클래스 형식)::(메서드 이름) 이렇게 해야 함
// 클래스 형식을 알아야 클래스의 필드와 메서드를 이용할 수 있음
Monster::Monster()
{
	name_ = "이름 없음";
}

// 오버로딩된 생성자
// 참고만 하는 용도라면 const를 꼭 붙이자!
Monster::Monster(const std::string &name)
{
	name_ = name;
}

void Monster::ShowName()
{
	std::cout << "몬스터의 이름 : " << name_ << std::endl;
}