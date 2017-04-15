/*
 * random.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * random.cpp는 난수 발생기를 다룹니다.
 * 게임에서 난수는 거의 필수적이므로 잘 알아두세요.
 * rand(), srand()가 아니라 random 클래스를 이용합니다.
 * std::default_random_engine과 std::uniform_int_distribution을 이용합니다.
 * 
 */

// std::cout의 출력을 도와주는 헤더 파일
#include <iomanip>

// 표준 입출력을 위한 C++의 헤더 파일
// using namespace std;는 이용하지 않음!
#include <iostream>

// C++11 이후부터 추가된 난수 발생기 전용 헤더 파일
// 이 헤더 파일이 있어야 난수 발생기를 사용할 수 있음!
#include <random>

// std::string을 위한 헤더 파일
// string.h가 아니라 string임!
#include <string>

// 난수 발생기의 기준(시드)을 위한 시간 전용 헤더 파일
#include <ctime>

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	// 난수를 고를 수 있도록 도와주는 것
	// default_random_engine은 mt19937을 뜻함!
	// 저게 뭐냐면 그냥 난수를 구하는 공식이라고 보면 됨!
	// 시간은 영원히 변하는 값! 따라서 진정한 난수 발생기를 만들 수 있음!
	std::default_random_engine random_generator(time(nullptr));

	// 최솟값부터 최댓값까지만 저장할 수 있는 것
	// 이름에 나와있듯이 정수형 자료형만 저장할 수 있음!
	// <> 안에 사용하고자 할 정수형 자료형을 입력하면 됨!
	std::uniform_int_distribution<int> probability(1, 100);
	
	// 아래에 있는 카드와 겹치므로 여기서는 횟수를 설정!
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "결과 : " << probability(random_generator) << std::endl;
		system("pause");
		std::cout << std::endl;
	}

	/* 난수 발생기를 이용한 카드 뽑기(가챠라고 하죠~) */
	std::default_random_engine card_random_generator(time(nullptr));
	
	// 정수형이 아닌 실수형도 있음!
	// 실수형 확률은 범위가 넓음
	std::uniform_real_distribution<float> card_probability(0.0000f, 1.0000f);

	// 카드 뽑기
	float result;
	int cash = 0;
	std::cout.precision(4); // 소수점 표현 범위 4개로 제한
	std::cout << std::fixed; // 소수점 고정 표현
	for (bool is_finish = false; is_finish == false;)
	{
		result = card_probability(card_random_generator);
		std::cout << "현재까지 쓴 돈 : " << cash << std::endl;
		std::cout << "현재 확률      : " << result << std::endl;
		if (result <= 0.0005f) // 희박한 확률
		{
			std::cout << "1등급 카드를 뽑으셨습니다!\n";
			//is_finish = true;
			//system("pause");
		} 
		else if (result <= 0.0100f) // 좀 희박한 확률
		{
			std::cout << "2등급 카드를 뽑으셨습니다!\n";
			//is_finish = true;
			//system("pause");
		}
		else if (result <= 0.0500f) // 무난한 확률
		{
			std::cout << "3등급 카드를 뽑으셨습니다!\n";
		}
		else if (result <= 0.1000f) // 보통 확률
		{
			std::cout << "4등급 카드를 뽑으셨습니다!\n";
		}
		else if (result <= 0.9999f) // 굉장히 높은 확률
		{
			std::cout << "5등급 카드를 뽑으셨습니다!\n";
		}
		cash += 5000; // 5천원
		system("pause");
		system("cls");
	}
	
	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}