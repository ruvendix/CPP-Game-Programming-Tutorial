/*
 * class.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * class.cpp는 클래스의 기초 내용을 알아봅니다.
 * 클래스는 객체의 정보와 기능을 하나로 묶은 개념이라고 생각하시면 됩니다.
 * 별로 어렵게 분석할 필요 없이 그냥 간단하게만 알아볼게요.
 */

// std::cout의 출력을 도와주는 헤더 파일
#include <iomanip>

// 표준 입출력을 위한 C++의 헤더 파일
// using namespace std;는 이용하지 않음!
#include <iostream>

// std::string을 위한 헤더 파일
// string.h가 아니라 string임!
#include <string>

// 이게 바로 클래스
// 클래스에는 접근 한정자가 있다!
// public    => 외부에서도 접근 가능
// protected => 상속 관계에서 접근 가능
// private   => 외부에서 접근 불가능
class Monster
{
public:
	// 클래스의 메서드(멤버 함수)는
	// public으로 만드는 경우가 많음!
	void Growl()
	{
		std::cout << "크아아!\n";
	}

	void set_name(const std::string &name)
	{
		name_ = name;
	}

	std::string get_name()
	{
		return name_;
	}
protected:

private:
	// std::string도 클래스!
	// 클래스의 필드(멤버 변수)에는 _을 붙임!
	std::string name_;
}; // 끝에 쌍반점 필수!

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	system("title 클래스 실험하기");

	// 클래스로 객체를 생성할 때는 이렇게 해야 함
	Monster monster;

	//monster.name_; // 그냥은 접근 불가능!
	monster.set_name("해럴드"); // 이렇게 접근해야 함!

	// 객체를 생성하면 메서드는 .을 이용해서 호출!
	std::cout << "몬스터의 이름 : " << monster.get_name() << std::endl;
	monster.Growl();

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}