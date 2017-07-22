/*
 * 파일 이름 : main.cpp
 * 만든 날짜 : 2017-07-22
 * 만든 사람 : Ruvendix
 *
 * 파일 설명 : 힙 메모리를 다루는 new와 delete를 테스트합니다.
 */

#include <cassert>
#include <iostream>

int PressEnter();

// rhs는 Right Hand Side의 약자로 오른쪽, 우변을 의미
int ReferValue(int& rhs);

int IndirectValue(int* pValue);

int main()
{
	//// 포인터는 Pointer의 약자로 p로 표시
	//// 포인터 같은 경우는 포인터라고 알려주는 게
	//// 유지보수 측면에서 굉장히 편함
	//int *pNum = new int;

	//// 포인터는 이렇게 nullptr인지 검사 필수!
	//assert(pNum != nullptr);
	//if (pNum == nullptr) printf("동적 할당에 실패했습니다. 대상 : pNum\n");

	//*pNum = 10;
	//printf("pNum의 역참조값 : %d\n", *pNum);

	//// 이렇게만 끝내면 메모리 누수(Memory Leak)가 발생함!
	//// 항상 new를 하면 delete도 같이 써주는 게 정석!
	//
	//// delete pNum;

	////////////////////////////////////////////////////////////////////////////

	//// int형 10개를 저장하는 배열
	//// 연속된 메모리를 할당하려면 반드시
	//// new[]으로 할당해야 함!
	//int *pNumArray = new int[10];

	//assert(pNumArray != nullptr);
	//if (pNumArray == nullptr) printf("동적 할당에 실패했습니다. 대상 : pNum\n");

	//for (int i = 0; i < 10; ++i)
	//{
	//	pNumArray[i] = i;
	//}

	//for (int i = 0; i < 10; ++i)
	//{
	//	printf("%d ", pNumArray[i]);
	//}
	//printf("\n");

	//// 연속된 메모리를 할당하면 반드시
	//// delete[]으로 해제해야 함!
	//delete[] pNumArray;

	//////////////////////////////////////////////////////////////////////////

	//int* pNum = new int;

	//assert(pNum != nullptr);
	//if (pNum == nullptr) printf("동적 할당에 실패했습니다. 대상 : pNum\n");

	//*pNum = 100;

	//// 참조자를 이용한 값 변경
	//printf("증가되기 전 pNum의 역참조값 : %d\n", *pNum);
	//ReferValue(*pNum);
	//printf("증가된 후 pNum의 역참조값   : %d\n\n", *pNum);

	//// 포인터를 이용한 값 변경
	//printf("증가되기 전 pNum의 역참조값 : %d\n", *pNum);
	//IndirectValue(pNum);
	//printf("증가된 후 pNum의 역참조값   : %d\n\n", *pNum);

	//delete pNum;

	//////////////////////////////////////////////////////////////////////////

	PressEnter();
		
	return 0;
}

int PressEnter()
{
	printf("계속 진행하려면 엔터를 누르세요.\n");
	getchar();

	return 0;
}

int ReferValue(int& rhs)
{
	return rhs++;
}

int IndirectValue(int* pValue)
{
	(*pValue)++;
	return 0;
}