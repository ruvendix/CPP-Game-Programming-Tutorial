/* 
 * constructors.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * constructors.cpp는 클래스의 생성자에 대해 알아봅니다.
 * 이제부터는 클래스 분할 때문에 파일 분할이 적용됩니다.
 * 파일을 분할할 때 필터와 폴더를 일치시킬 테니 참고하세요.
 */

// std::cout의 출력을 도와주는 헤더 파일
#include <iomanip>

// 표준 입출력을 위한 C++의 헤더 파일
// using namespace std;는 이용하지 않음!
#include <iostream>

// std::string을 위한 헤더 파일
// string.h가 아니라 string임!
#include <string>

// 기본 경로에서 폴더를 찾아야 함!
#include "monster/monster.h"

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	system("title 생성자 실험하기");

	// 기본 생성자가 있어야 생성 가능!
	Monster monster_list[100];

	// 첫 번째와 마지막 첨자로 확인해보기
	monster_list[0].ShowName();
	monster_list[99].ShowName();

	std::cout << std::endl;

	// 오버로딩된 생성자를 이용할 때는
	// 함수를 호출하는 것처럼 인자를 넘기면 됨
	Monster dragon("용");
	Monster dark_elf("암흑 요정");

	dragon.ShowName();
	dark_elf.ShowName();	

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}