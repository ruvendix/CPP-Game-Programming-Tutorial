/*
* 파일 이름 : main.cpp
* 만든 날짜 : 2017-07-19
* 만든 사람 : Ruvendix
*
* 파일 설명 : 포인터 기초 내용을 테스트합니다.
*/

#include <cassert>
#include <iostream>

int AddOne(int* pNum);

int main()
{
	//// 변수의 주소
	//int intNum;
	//std::cout << "intNum의 주소   : " << &intNum << std::endl; // 16진수
	//std::cout << "intNum의 주소   : " << reinterpret_cast<int>(&intNum)
	//	<< std::endl << std::endl; // 10진수

	//float floatNum;
	//std::cout << "floatNum의 주소 : " << &intNum << std::endl; // 16진수
	//std::cout << "floatNum의 주소 : " << reinterpret_cast<int>(&floatNum)
	//	<< std::endl << std::endl; // 10진수

	////////////////////////////////////////////////////////////////////////////

	//// nullptr => 주소가 0x00000000인 포인터
	//char* pChar = nullptr;
	////std::cout << pChar << std::endl; // 16진수 => 출력 불가
	//std::cout << reinterpret_cast<int*>(pChar) << std::endl << std::endl; // 10진수	

	////////////////////////////////////////////////////////////////////////////

	//// 포인터에 변수 주소 넣기
	//int  num = 10;
	//int* pNum = &num;

	//std::cout << "num의 값   : " <<  num << " " << *pNum << std::endl;
	//std::cout << "num의 주소 : " << &num << " " <<  pNum << std::endl << std::endl;

	////////////////////////////////////////////////////////////////////////////

	//// 역참조 연산자와 nullptr
	//char* pData = nullptr;
	//int result;

	////result = *pData; // 오류 발생!

	////assert(pData != nullptr); // nullptr를 판별할 때 쓰는 Debug 모드 전용 매크로 함수

	//if (pData != nullptr)
	//{
	//	result = *pData;
	//}

	////////////////////////////////////////////////////////////////////////////

	//int upNum = 5;

	//for (int i = 0; i < 10; ++i)
	//{
	//	AddOne(&upNum); // upNum의 주소가 pNum에 복사! 이게 정말 중요!
	//	std::cout << upNum << " ";
	//}
	//std::cout << std::endl;

	return 0;
}

int AddOne(int* pNum)
{
	(*pNum)++; // *pNum부터 하고 ++ 연산
	return 0;
}