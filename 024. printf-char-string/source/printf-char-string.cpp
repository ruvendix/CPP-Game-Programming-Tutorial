/* 
 * printf-char-string.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * printf-char-string.cpp는 C 스타일의 표준 출력과 문자열을 알아봅니다.
 * printf()는 형식에 맞는 것만 제대로 출력하므로 cout보다 안전합니다.
 * cout은 여러 형식에 작동하므로 의도하지 않은 결과를 출력할 수도 있습니다.
 *
 * 지금까지는 문자열을 string으로 사용했는데 원래는 char를 이용해야 합니다.
 * char가 여러 개 있으면 문자열로 다룰 수 있습니다.
 */

// std::cout의 출력을 도와주는 헤더 파일
#include <iomanip>

// 표준 입출력을 위한 C++의 헤더 파일
// using namespace std;는 이용하지 않음!
// cstdio도 포함되어있으므로 C 스타일의 표준 입출력도 사용 가능!
#include <iostream>

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	system("title printf()와 char 문자열");

	//// printf()는 C 스타일의 표준 출력 함수
	//// 서식 지정자에 맞는 형식만 출력하므로
	//// 제대로 알고 있어야 자유자재로 사용 가능
	//printf("Hello C World~\n\n");

	//// 정수는 %d로, 실수는 %f를 이용
	//int int_num = 10;
	//float float_num = 20.0f;
	//
	//// + => 부호 출력
	//// 0 => 0으로 채움
	//// 5 => 5자리 확보(부호 포함)
	//printf("int_num   : %+05d\n\n", int_num);

	//// - => 왼쪽 정렬
	//// 0 => -를 만나면 무시
	//// 9 => 9자리 확보(부호, 소수점 포함)
	//// . => 소수점 이하 자리 확보
	//// 4 => 소수점 이하 4자리 확보
	//printf("float_num : %-09.4f\n\n", float_num);

	//// for문 하나로 별 찍기
	//// * => 지정된 개수만큼 너비 설정(0과 1은 같음)
	//for (int i = 0; i < 5; ++i)
	//{
	//	printf("%*c\n", i + 1, '*');
	//}

	//// 별 찍기를 위한 문자열
	//char *asterisk;
	//const int kSize = 6;
	//asterisk = new char[kSize];

	//// 별 문자 삽입
	//for (int i = 0; i < kSize - 1; ++i)
	//{
	//	asterisk[i] = '*';
	//}
	//asterisk[kSize - 1] = '\0';

	//// for문 하나로 별 찍기
	//for (int i = kSize - 2; i >= 0; --i)
	//{
	//	printf("%s\n", asterisk + i);
	//}

	//delete asterisk;

	// char 배열로 문자열 출력하기
	char string1[128] = "Hello World~";
	printf("<문자열 통째로 출력>\n");
	printf("%s\n\n", string1);

	// char 배열로 문자 하나씩 넣기
	// '\0'은 종료 문자라고 해서 문자열의 끝을 나타내는 문자
	// 종료 문자가 없으면 프로그램이 문자열의 끝을 파악할 수 없음
	char string2[128] = {'A', 'P', 'P', 'L', 'E', '\0'};
	printf("<문자 개별로 출력>\n");
	printf("%s\n", string2);

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}