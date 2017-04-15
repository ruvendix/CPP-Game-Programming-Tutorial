/*
 * variables.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * variables.cpp는 기본 자료형인 int, float, double을 출력합니다.
 * double이 float보다 더 정밀도가 높지만 지금은 float만 사용해도 괜찮습니다.
 * float을 사용하기 귀찮으면 double을 사용하셔도 됩니다.
 *
 */

// 정수와 실수를 섞어서 연산할 때
// 해당되는 경고를 띄워주지 않는 코드
// 프로그램의 규모가 커져서 디버깅이 힘들다면
// 이 코드를 잘 활용해야 함!
//#pragma warning(disable:4244)

// 표준 입출력을 위한 C++의 헤더 파일
// using namespace std;는 이용하지 않음!
// 당분간은 printf() 대신 std::cout을 사용하겠음!
#include <iostream>

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	// int는 기본 자료형 중 정수!
	// 소수점을 사용하지 않는다면
	// 앞으로 웬만한 숫자는 int를 이용!
	int zombies = 300; // zombies라는 공간에 300을 넣겠다!라는 뜻
	std::cout << "현재 좀비의 수 : " << zombies << std::endl;

	zombies = 200; // zombies는 이렇게 값 변경도 가능!
	std::cout << "현재 좀비의 수 : " << zombies << std::endl;

	zombies = 200 + 50; // +는 수학의 덧셈과 같음!
	std::cout << "현재 좀비의 수 : " << zombies << std::endl << std::endl;

	// float은 기본 자료형 중 실수!
	// 소수점 단계까지 숫자가 정밀해야 한다면
	// float이나 double을 이용!
	// 고도의 과학 또는 수학 계산을 다루는 게
	// 아니라면 당분간은 float으로도 충분!
	float plants = 200.8f; // f는 float형이다!라고 알리는 것!
	std::cout << "현재 식물의 수 : " << plants << std::endl << std::endl;

	float small_plants = 200.0f;
	float big_plants   = 200.0f;

	// *는 수학의 곱하기와 같음! 0을 곱하면 무조건 0이 됨!
	std::cout << "현재 식물의 수 : " << small_plants * big_plants << std::endl;

	// /는 수학의 나눗셈과 같음! big_plants가 0이라면 수학적 오류 발생!
	// 그러므로 big_plants 위치에 0을 넣는 실수를 범하지 말자!
	std::cout << "현재 식물의 수 : " << small_plants / big_plants << std::endl << std::endl;

	// 소괄호는 먼저 작업을 처리하라는 표시!
	float plants_damage = (small_plants + big_plants) * 8.0f;

	// 정수와 실수의 연산은 손해가 발생하지만
	// 크게 신경 쓸 필요는 없음!
	// 경고가 뜨는 게 귀찮으면
	// #pragma warning(disable:4244)를 맨 위에 입력!
	float zombies_health = static_cast<float>(zombies * 20);

	std::cout << "현재 식물들의 피해량 : " << plants_damage << std::endl;
	std::cout << "현재 좀비들의 생명력 : " << zombies_health << std::endl << std::endl;
	std::cout << "식물들이 좀비들을 일제히 공격한다!" << std::endl << std::endl;

	// 좀비들의 변화된 생명력 = 좀비들의 현재 생명력 - 식물들의 피해량
	zombies_health = zombies_health - plants_damage;
	
	std::cout << "현재 좀비들의 생명력 : " << zombies_health << std::endl;

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}