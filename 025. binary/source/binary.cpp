/* 
 * binary.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * binary.cpp는 2진수를 알아보고 10진수를 2진수로 변경해봅니다.
 * 2진수는 1과 0으로 이루어진 숫자를 뜻합니다.
 * 컴퓨터의 내부 체계는 2진수로 되어있고 우리는 그걸 10진수로 보는 것뿐입니다.
 * 2진수의 자리수 하나는 숫자 하나를 뜻합니다. 다시 말하면 1비트를 뜻합니다.
 * 1비트가 8개 모이면 1바이트가 되고, 여기서는 1바이트로 10진수를 2진수로 변경해봅니다.
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
	system("title 2진수 체계 실험하기");

	// 1바이트 2진수 체계 배열(룩업 테이블)
	int byte_binary[8] = {128, 64, 32, 16, 8, 4, 2, 1};
	int result_binary[8];
	int decimal;

	bool is_done = false;
	while (is_done == false)
	{
		printf("10진수를 입력하세요(취소는 -1) : ");

		// C 스타일의 표준 입력
		// 서식 지정자와 & 연산자를 이용해야 함!
		scanf("%d", &decimal);

		if (decimal == -1)
		{
			is_done = true;
		}
		else
		{
			for (int i = 0; i < 8; ++i)
			{
				// 10진수가 2진수의 자리보다 크다면
				if (decimal >= byte_binary[i])
				{
					// 10진수에서 2진수의 자리를 뺀 다음
					// 변환된 2진수를 1로 설정
					decimal -= byte_binary[i];
					result_binary[i] = 1;
				}
				else
				{
					// 10진수가 2진수의 자리보다 작으므로
					// 변환된 2진수를 0으로 설정
					result_binary[i] = 0;
				}
			}

			printf("2진수로 변환한 결과 : ");
			for (int i = 0; i < 8; ++i)
			{
				printf("%d", result_binary[i]);
			}
			printf("\n");

			system("pause");
			system("cls");
		}
	}

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}