/*
 * 파일 이름 : main.cpp
 * 만든 날짜 : 2017-07-19
 * 만든 사람 : Ruvendix
 *
 * 파일 설명 : 메모리 함수와 버퍼를 테스트하는 프로그램입니다.
 */

#include <iostream>

int main()
{
	//// sizeof()
	//char   charNum;
	//int    intNum;
	//float  floatNum;
	//double doubleNum;

	//std::cout << "  char의 크기 : " << sizeof(charNum)   << std::endl;
	//std::cout << "   int의 크기 : " << sizeof(intNum)    << std::endl;
	//std::cout << " float의 크기 : " << sizeof(floatNum)  << std::endl;
	//std::cout << "double의 크기 : " << sizeof(doubleNum) << std::endl << std::endl;

	//// 버퍼 => 연속된 메모리 공간, 배열이라고 생각하면 됩니다.
	//char charBuffer[5];
	//int  intBuffer[5];

	//std::cout << "charBuffer의 크기 : " << sizeof(charBuffer) << std::endl;
	//std::cout << " intBuffer의 크기 : " << sizeof(intBuffer)  << std::endl << std::endl;

	//// 메모리 함수
	//const int BUFFER_LENGTH = 5;

	//char oneByteBuffer[BUFFER_LENGTH];
	//memset(oneByteBuffer, 'A', sizeof(oneByteBuffer));
	//for (int i = 0; i < BUFFER_LENGTH; ++i)
	//{
	//	std::cout << oneByteBuffer[i] << " ";
	//}
	//std::cout << std::endl;

	//int fourByteBuffer[BUFFER_LENGTH];
	//memset(fourByteBuffer, 'A', sizeof(fourByteBuffer));
	//for (int i = 0; i < BUFFER_LENGTH; ++i)
	//{
	//	std::cout << fourByteBuffer[i] << " ";
	//}
	//std::cout << std::endl;

	//int copyBuffer[BUFFER_LENGTH];
	//memcpy(copyBuffer, fourByteBuffer, sizeof(fourByteBuffer));
	//for (int i = 0; i < BUFFER_LENGTH; ++i)
	//{
	//	std::cout << fourByteBuffer[i] << " ";
	//}
	//std::cout << std::endl;

	return 0;
}