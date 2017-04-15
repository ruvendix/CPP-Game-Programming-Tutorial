/*
 * function.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * function.cpp는 함수에 대해서 알아봅니다.
 * 함수는 중복되는 소스 코드를 줄일 수 있고, 소스 코드의 길이를 짧게 만들 수 있습니다.
 * 중복되는 작업을 함수로 처리하면 좀 더 가독성이 향상됩니다.
 * 함수를 만드는 기준은 없으므로 최대한 함수를 많이 만들어보세요.
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

// 사람의 수를 입력받는 함수
// 매개변수는 없음
// 반환 형식은 int
int InputHumanNum()
{
	int num_of_human;
	std::cout << "인간의 수를 입력하세요 : ";
	std::cin >> num_of_human;
	std::cout << "인간의 수가 " << num_of_human << "으로 설정되었습니다.\n\n";
	return num_of_human;
}

// 해골의 수를 입력받는 함수
// 매개변수는 없음
// 반환 형식은 int
int InputSkeletonNum()
{
	int num_of_skeleton;
	std::cout << "해골의 수를 입력하세요 : ";
	std::cin >> num_of_skeleton;
	std::cout << "해골의 수가 " << num_of_skeleton << "으로 설정되었습니다.\n\n";
	return num_of_skeleton;
}

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	system("title 전투 상황 실험");

	// 인간의 정보
	float human_hp = 250;
	float human_max_hp = human_hp;
	float human_attack = 0.6f;
	float human_damage = 200.0f;

	// 해골의 정보
	float skeleton_hp = 250;
	float skeleton_max_hp = skeleton_hp;
	float skeleton_attack = 0.4f;
	float skeleton_damage = 150.0f;

	int num_of_human, max_num_of_human;
	int num_of_skeleton, max_num_of_skeleton;

	// 인간의 수를 입력받는 함수
	max_num_of_human = num_of_human = InputHumanNum();

	// 해골의 수를 입력받는 함수
	max_num_of_skeleton = num_of_skeleton = InputSkeletonNum();
	
	// 난수를 위한 변수들
	std::default_random_engine random_generator(static_cast<unsigned>(time(nullptr)));
	std::uniform_real_distribution<float> attack_probability(0.0f, 1.0f);

	// 공격 성공 확률을 위한 변수
	float attack_result;

	// 공격 자격을 가지기 위한 변수
	char turn = 'H';

	// 인간의 수와 해골의 수가 0 이상일 때만 전투!
	// 어느 한쪽이 패배하면 그걸로 전투는 종료!
	while ((num_of_human > 0) &&
		(num_of_skeleton > 0))
	{
		// 공격 확률 정하기
		attack_result = attack_probability(random_generator);

		if (turn == 'H')
		{
			if (attack_result <= human_attack)
			{
				skeleton_hp -= human_damage;

				if (skeleton_hp < 0)
				{
					// 다음 해골 설정
					skeleton_hp = skeleton_max_hp;

					num_of_skeleton--;
				}
			}

			turn = 'S';
		}
		else
		{
			if (attack_result <= skeleton_attack)
			{
				human_hp -= skeleton_damage;

				if (human_hp < 0)
				{
					// 다음 인간 설정
					human_hp = human_max_hp;

					num_of_human--;
				}
			}

			turn = 'H';
		}
	}

	std::cout << "전투가 종료되었습니다!\n\n";
	std::cout << "전투 결과를 보여드리겠습니다.\n\n";
	
	// 누가 전투에서 이겼는가?
	if (num_of_human > 0)
	{
		std::cout << "<인간의 승리!>\n";
	}
	else
	{
		std::cout << "<해골의 승리!>\n";
	}

	std::cout << "남은 인간의 수 : " << num_of_human << std::endl;
	std::cout << "남은 해골의 수 : " << num_of_skeleton << std::endl;
	std::cout << "잃은 인간의 수 : " << max_num_of_human - num_of_human << std::endl;
	std::cout << "잃은 해골의 수 : " << max_num_of_skeleton - num_of_skeleton << std::endl;

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}