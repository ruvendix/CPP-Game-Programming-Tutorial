/* 
 * fileIO-standardIO.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * fileIO-standardIO.cpp는 파일 입출력과 표준 입출력에 대해 알아봅니다.
 * 파일 입출력과 표준 입출력의 공통된 내용은 공백을 다루는 것입니다.
 * 저번 포스팅에서 상점을 만들 때 공백을 다루는 부분의 설명을 생략했는데
 * 이번에는 왜 공백을 다룰 때 그렇게 해야 하는지 알려드리겠습니다.
 */

// 파일 입출력을 위한 C++의 헤더 파일
#include <fstream>

// std::cout의 출력을 도와주는 헤더 파일
#include <iomanip>

// 표준 입출력을 위한 C++의 헤더 파일
// using namespace std;는 이용하지 않음!
#include <iostream>

// std::string을 위한 헤더 파일
// string.h가 아니라 string임!
#include <string>

// 프로그램의 진입점
// 즉, 프로그램이 시작되는 부분!
int main()
{
	system("title 파일 입출력과 표준 입출력");

	//// 파일에 출력
	//// 파일이 생성되는 경로는 프로젝트의 기본 경로
	//std::ofstream write_file("test.txt");

	//// 파일 스트림을 생성하지 못한 경우
	//if (write_file.fail() == true)
	//{
	//	perror("test.txt를 생성하지 못했습니다!");
	//  exit(EXIT_FAILURE);
	//}

	//// 파일에 문자열 출력하기
	//std::string test = "Hello World~\n";

	//write_file << test;

	//std::cout << "파일에 문자열을 출력했습니다.\n";

	//// 파일 스트림 해제
	//write_file.close();

	//// 파일에서 입력
	//std::ifstream read_file("test.txt");

	//// 파일 스트림을 생성하지 못한 경우
	//if (read_file.fail() == true)
	//{
	//	perror("test.txt를 읽어오지 못했습니다!");
	//	exit(EXIT_FAILURE);
	//}

	//// 파일에서 정보를 읽어오려면
	// 정보를 저장할 공간이 필요함!
	//std::string test;

	//// 파일에서 문자열 읽어오기
	//read_file >> test;

	//std::cout << test << std::endl;

	//// 파일에서 여러 문자열 읽어오기
	//// 입력 부분도 함수를 이용하는 것이므로
	//// 반환값이 있고, 그 반환값을 이용하면
	//// 참이냐 거짓이냐를 판단할 수 있음!
	//for ( ; read_file >> test; )
	//{
	//	std::cout << test << std::endl;
	//}

	// 공백을 포함한 문자열 읽어오기
	//getline(read_file, test);

	//std::cout << test << std::endl;

	//// 공백을 포함한 여러 문자열 읽어오기
	//for ( ; getline(read_file, test); )
	//{
	//	std::cout << test << std::endl;
	//}

	//std::cout << "파일에서 문자열을 읽어왔습니다.\n";

	//read_file.close();

	////// 공백을 포함한 문자열 입력받기
	//std::string test;

	////std::cout << "공백을 포함한 문자열을 입력하세요\n";
	////std::cout << " >> ";
	//
	//// 공백을 포함한 문자열을 입력받을 때는
	//// getline()을 이용해야 함!
	//std::cout << "문자열을 입력하세요\n";
	//std::cout << " >> ";
	//std::cin >> test;
	//std::cout << "\n입력한 문자열 : " << test << std::endl << std::endl;

	//// 입력 버퍼에 남아있는 내용을
	//// 읽어서 버리는 함수
	//// 기본값은 1, eof
	////
	//// 지정된 개수만큼 읽어서
	//// 지정된 값이 나오기 전까지
	//// 모든 내용을 버림
	//std::cin.ignore(128, '\n');

	//std::cout << "문자열을 입력하세요\n";
	//std::cout << " >> ";
	//getline(std::cin, test);
	//std::cout << "\n입력한 문자열 : " << test << std::endl;

	// std::cin의 오류 발생
	int num;

	for ( ; ; )
	{
		std::cout << "숫자를 입력하세요 : ";
		std::cin >> num;

		// 형식에 맞지 않는 입력이 발생하면
		// failbit가 설정됨
		if (std::cin.fail() == true)
		{
			std::cout << "입력 오류 발생! 오류 번호 : " << std::cin.rdstate() << std::endl;

			// 입력 오류가 발생되면
			// std::cin의 오류는 failbit로 설정됨!
			// 따라서 오류 상태를 초기화해줘야
			// ignore()가 정상적으로 작동함!
			// 그래서 clear()부터 써줘야 됨!
			std::cin.clear();

			// ignore()는 std::cin에
			// 오류가 없을 때 정상적으로 작동함!
			// 즉, goodbit일 때만 작동이 보장됨!
			std::cin.ignore(128, '\n');

			system("pause");
		}

		std::cout << "입력한 숫자 : " << num << std::endl << std::endl;
	}

	// 자동 종료 방지!
	system("pause");

	// 프로그램이 정상적으로 종료된다는 것을 의미
	// exit(EXIT_SUCCESS); 이것과 비슷함!
	return 0;
}