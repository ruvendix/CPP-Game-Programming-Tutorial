/*
 * switch-case.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * switch-case.cpp는 switch ~ case문을 알아봅니다.
 * if ~ else if를 많이 사용해야 한다면 switch ~ case를 사용하세요.
 * switch ~ case는 룩업 테이블이라는 기법으로 대체할 수 있지만
 * 룩업 테이블은 좀 어려우므로 먼저 switch ~ case에 익숙해지세요.
 * 귀찮으면 그냥 if ~ else if를 마구 사용하셔도 됩니다.
 *
 * 세 번째 게임을 위해 간단히 객체 충돌 상황을 연출해볼 겁니다.
 * if ~ else if, switch ~ case, 룩업 테이블 이렇게 3개를 보여드릴게요.
 */

 // 표준 입출력을 위한 C++의 헤더 파일
 // using namespace std;는 이용하지 않음!
 // cstdio도 포함되어있으므로 C 스타일의 표준 입출력도 사용 가능!
#include <iostream>

// std::string을 위한 헤더 파일
// string.h가 아니라 string임!
#include <string>

// std::vector를 위한 헤더 파일
// 반드시 이 헤더 파일을 포함해야 함!
#include <vector>

void TestIfStatement(const char player)
{
	// if문은 위에서부터 차례대로 검사
	if (player == '#')
	{
		printf("벽에 부딪혔습니다!\n");
	}
	else if (player == 'S')
	{
		printf("뱀을 만났습니다!\n");
	}
	else if (player == 'O')
	{
		printf("구멍에 빠졌습니다!\n");
	}
	else if (player == 'T')
	{
		printf("나무에 부딪혔습니다!\n");
	}
	else if (player == 'C' ||
		player == 'D')
	{
		printf("여행자와 부딪혔습니다!\n");
	}
	else
	{
		printf("아무런 이상이 없습니다!\n");
	}
}

void TestSwitchCaseStatement(const char player)
{
	const char kWall = '#';

	// switch ~ case는 break로 탈출
	// case는 if문과 다르게 중간 조건을
	// 검사하지 않고 한번에 건너뜀
	// 따라서 break가 없으면 이후의
	// 조건들도 검사하게 됨
	// case는 label이라서 건너뛰는 게 가능!
	// label의 대표적인 예는 goto문
	switch (player)
	{
		// case에는 상수만 가능!
		// const를 붙이면 case에도 사용 가능!
		// 단! 상수값이 무조건 있어야 함!
	case kWall:
		printf("벽에 부딪혔습니다!");
		break;
	case 'S':
		printf("뱀을 만났습니다!");
		break;
	case 'O':
		printf("구멍에 빠졌습니다!");
		break;
	case 'T':
		printf("나무에 부딪혔습니다!");
		break;

		// case가 겹치면
		// 둘 다 처리됨
	case 'C':
	case 'D':
		printf("여행자와 부딪혔습니다!");
		break;

		// 기본 경우
		// case에 하나도 해당되지 않을 경우
	default:
		printf("아무런 이상이 없습니다.");
		break;
	}
	printf("\n");
}

void TestLookupTable(const char player)
{
	std::vector<char> object_vec = { '#', 'S', 'O', 'T', 'C', 'D' };
	std::vector<std::string> guide_vec =
	{ "벽에 부딪혔습니다!", "뱀을 만났습니다!", "구멍에 빠졌습니다!",
	 "나무에 부딪혔습니다!", "여행자와 부딪혔습니다!", "여행자와 부딪혔습니다!" };

	// 객체 배열을 처음부터 검사
	// 원래 룩업 테이블은 상수를 이용하기 때문에
	// 검사 단계를 거치지는 않지만,
	// 이 경우는 char로 판단해야 하므로 검사가 필요함!
	for (int i = 0; i < static_cast<int>(object_vec.size()); ++i)
	{
		// 객체 배열의 요소와 캐릭터가 일치한다면
		if (object_vec[i] == player)
		{
			// string을 %s에 이용하려면
			// c_str() 또는 data()를 사용해야 함!
			printf("%s\n", guide_vec[i].c_str());
			return;
		}
	}

	// 객체 배열의 요소와 캐릭터가 일치하지 않는다면
	printf("아무런 이상이 없습니다.\n");

	object_vec.clear();
	guide_vec.clear();
}

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	system("title switch ~ case문 실험하기");

	// 소스 코드를 줄이기 위해 룩업 테이블 이용
	std::vector<char> test_vec = { '#', 'S', 'O', 'T', 'C', 'D', '&', '*' };

	//if ~else if로 처리
	for (int i = 0; i < static_cast<int>(test_vec.size()); ++i)
	{
		TestIfStatement(test_vec[i]);
	}

	//// switch ~ case로 처리
	//for (int i = 0; i < static_cast<int>(test_vec.size()); ++i)
	//{
	//	TestSwitchCaseStatement(test_vec[i]);
	//}

	//// 룩업 테이블로 처리
	//for (int i = 0; i < static_cast<int>(test_vec.size()); ++i)
	//{
	//	TestLookupTable(test_vec[i]);
	//}

	test_vec.clear();

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}