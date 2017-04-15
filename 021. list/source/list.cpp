/* 
 * vector.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * list.cpp는 STL 중에서 vector를 알아봅니다.
 * list는 vector처럼 크기가 늘어날 수도 있고,
 * 줄어들 수도 있는 유연한 자료구조입니다.
 * list는 삽입과 삭제가 빠르지만, 검색은 느린 자료구조입니다.
 * 간단하게 push_back(), push_front(), begin(), end(), remove() 정도만 알아봅니다.
 */

// std::cout의 출력을 도와주는 헤더 파일
#include <iomanip>

// 표준 입출력을 위한 C++의 헤더 파일
// using namespace std;는 이용하지 않음!
#include <iostream>

// std::string을 위한 헤더 파일
// string.h가 아니라 string임!
#include <string>

// std::list를 위한 헤더 파일
// 반드시 이 헤더 파일을 포함해야 함!
#include <list>

void ShowItems(const std::list<std::string> &item_list);

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	system("title list 실험");

	// 크기가 0인 list 생성
	// STL은 <> 안에 자료형을 써야 함!
	std::list<int> empty_list;
	
	// list의 크기는 size()로 알아낼 수 있음
	std::cout << "empty_list의 크기 : " << empty_list.size() << std::endl;

	// 크기가 10인 list 생성
	std::list<int> ten_list(10);
	std::cout << "ten_list의 크기   : " << ten_list.size() << std::endl << std::endl;

	// std::string을 담는 list 생성
	// 그냥 대괄호를 쓰려면 C++11 이상부터 가능!
	std::list<std::string> item_list = {"장갑", "검", "방패"};
	ShowItems(item_list);

	// 맨 뒤와 앞에 아이템 추가
	std::cout << "<주먹밥, 회복약 추가!>\n";
	item_list.push_back("주먹밥");
	item_list.push_front("회복약");
	ShowItems(item_list);

	// 맨 뒤와 앞에 있는 아이템 삭제
	std::cout << "<주먹밥, 회복약 삭제!>\n";
	item_list.pop_back();
	item_list.pop_front();
	ShowItems(item_list);

	// 검 삭제
	std::cout << "<검 삭제!>\n";
	item_list.remove("검");
	ShowItems(item_list);

	// 폭탄, 곡괭이, 훅샷 추가
	// 반복자로 곡괭이 삭제
	std::cout << "<폭탄, 곡괭이, 훅샷 추가하고 곡괭이 삭제!>\n";
	item_list.push_back("폭탄");
	item_list.push_back("곡괭이");
	item_list.push_back("훅샷");

	// auto를 사용할 때는 자료형이 뭔지 파악해야 함!
	// std::list<std::string>::iterator를 모른다면
	// auto를 쓰지 말고 저것부터 연습!
	for (auto iter = item_list.begin(); iter != item_list.end(); ++iter)
	{
		// 곡괭이를 검색
		if (*iter == "곡괭이")
		{
			// erase()는 현재 요소를 삭제하고
			// 다음 주소를 반환하기 때문에
			// iter로 다음 주소를 받아야 함!
			// erase()가 iter를 삭제하므로 그냥 ++iter로는
			// 다음 위치를 알아낼 수 없음!
			// 하지만 vector는 빈 자리가 채워지므로 ++iter로도 가능
			// 
			// erase(iter++)는 주소를 하나 넘어갈 수 있으므로 추천하지 않음
			iter = item_list.erase(iter);
		}
	}
	ShowItems(item_list);

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}

void ShowItems(const std::list<std::string> &item_list)
{
	// C++11 이상부터는 귀찮으면 auto로 대체
	// auto iter가 std::list<std::string>::iterator를 알아서 찾아줌
	// iterator도 클래스! 어떤 형식의 클래스인지 알려줘야 함!
	// 반복자의 대상이 const라면 const_iterator를 이용해야 함!
	//
	// begin()은 가장 첫 번째 요소의 주소를 반환
	// end()는 맨 뒤에 있는 요소 다음의 주소를 반환
	// 따라서 iter가 증가하다가 마지막 다음 요소의 주소에 접근하면
	// end()의 반환값과 똑같아지므로 반복문을 탈출하게 됨!
	for (std::list<std::string>::const_iterator iter = item_list.begin();
		iter != item_list.end(); ++iter)
	{
		// iter는 요소의 위치를 갖고 있음
		// 따라서 요소에 접근하려면 * 연산자를 이용해야 함!
		std::cout << *iter << std::endl;
	}
	std::cout << "------------------------------------------\n";
}