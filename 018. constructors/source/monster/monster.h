/*
 * monster.h
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * monster.h는 Monster 클래스가 선언되어있는 파일입니다.
 * 인라인 형식도 있지만 외부에서 정의하는 형식도 있습니다.
 */

// <프로젝트 이름>_<소스 파일의 경로>_<소스 파일의 이름>
#ifndef CONSTRUCTORS_MONSTER_MONSTER_H_
#define CONSTRUCTORS_MONSTER_MONSTER_H_

#include <string>

class Monster
{
public:
	// 기본 생성자 => 디폴트 생성자라고도 함
	// 생성자는 객체가 생성될 때 자동 호출되는 함수
	Monster();
	
	// 생성자는 오버로딩이 가능함!
	// 오버로딩은 함수의 식별자가 같을 때
	// 함수의 매개변수로 함수를 구분하는 기법을 말함
	Monster(const std::string &name);

	void ShowName();
protected:

private:
	std::string name_;
};

#endif