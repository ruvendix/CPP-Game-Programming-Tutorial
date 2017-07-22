/*
 * 파일 이름 : main.cpp
 * 만든 날짜 : 2017-07-22
 * 만든 사람 : Ruvendix
 *
 * 파일 설명 : 메모리 영역 중 Data와 Stack을 알아봅니다.
 */

int g_num; // 전역 변수, 초기화하지 않으면 0, BSS 영역

// 전역 변수는 예약된 Stack 영역 크기 1MB 넘는 게 가능
int g_killStack[1000000];

int main()
{
	int num; // 지역 변수, Stack 영역

	// Stack 영역의 예약된 크기는 1MB
	// 살짝 넘는 건 가능하지만 2MB 이상은 불가능
	char killStack[1000000];

	return 0;
}