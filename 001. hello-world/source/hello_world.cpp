/*
 * hello_world.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * hello_world.cpp는 표준 출력 객체인 std::cout을
 * 이용해서 간단한 문장(문자열)을 출력합니다.
 *
 */

// 표준 입출력을 위한 C++의 헤더 파일
// using namespace std;는 이용하지 않음!
#include <iostream>

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	// 구글 코딩 가이드에서는 printf()를 사용하라고 하지만
	// 어차피 강의에서도 나중에 printf()가 등장하므로
	// 그때까지는 std::cout을 사용하겠음!
	// std::endl은 '\n'과 동시에 출력 버퍼를 비움!
	std::cout << "Hello Game Programming World~" << std::endl << std::endl
		<< "언제나 첫 시작은 Hello World~\n\n";

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}