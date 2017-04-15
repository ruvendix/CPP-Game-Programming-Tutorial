/* 
 * vector.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * vector.cpp는 STL 중에서 vector를 알아봅니다.
 * vector는 배열과 비슷하지만 크기가 늘어날 수도 있고,
 * 줄어들 수도 있는 유연한 배열입니다.
 * vector는 삽입과 삭제가 어렵지만, 검색은 쉬운 자료구조입니다.
 * 간단하게 push_back(), pop_back(), back() 정도만 알아봅니다.
 * resize(), reserve()는 생략합니다.
 */

// std::cout의 출력을 도와주는 헤더 파일
#include <iomanip>

// 표준 입출력을 위한 C++의 헤더 파일
// using namespace std;는 이용하지 않음!
#include <iostream>

// std::string을 위한 헤더 파일
// string.h가 아니라 string임!
#include <string>

// std::vector를 위한 헤더 파일
// 반드시 이 헤더 파일을 포함해야 함!
#include <vector>

void ShowItems(const std::vector<std::string> &item_vec);

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	system("title vector 실험");

	// 크기가 0인 vector 생성
	// STL은 <> 안에 자료형을 써야 함!
	std::vector<int> empty_vec;
	
	// vector의 크기는 size()로 알아낼 수 있음
	std::cout << "empty_vec의 크기 : " << empty_vec.size() << std::endl;

	// 크기가 10인 vector 생성
	std::vector<int> ten_vec(10);
	std::cout << "ten_vec의 크기   : " << ten_vec.size() << std::endl << std::endl;

	// std::string을 담는 vector 생성
	// 그냥 대괄호를 쓰려면 C++11 이상부터 가능!
	std::vector<std::string> item_vec = {"장갑", "검", "방패"};
	ShowItems(item_vec);

	// 새로운 아이템 추가
	std::cout << "주먹밥, 회복약 추가!\n";
	item_vec.push_back("주먹밥");
	item_vec.push_back("회복약");
	ShowItems(item_vec);

	// 맨 뒤에 있는 아이템 삭제
	std::cout << "회복약 삭제!\n";
	item_vec.pop_back();
	ShowItems(item_vec);

	// 맨 뒤에 있는 아이템을 두 번째 아이템으로 옮기기
	// 두 번째 아이템은 정보가 삭제됨
	std::cout << "검 삭제!\n";
	item_vec[1] = item_vec.back();
	ShowItems(item_vec);

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}

void ShowItems(const std::vector<std::string> &item_vec)
{
	for (int i = 0; i < static_cast<int>(item_vec.size()); ++i)
	{
		std::cout << item_vec[i] << std::endl;
	}
	std::cout << "--------------------\n";
}