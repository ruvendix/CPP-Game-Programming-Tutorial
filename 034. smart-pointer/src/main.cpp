/*
 * 파일 이름 : main.cpp
 * 만든 날짜 : 2017-07-24
 * 만든 사람 : Ruvendix
 *
 * 파일 설명 : 스마트 포인터를 테스트합니다.
 */

#include <cassert>
#include <iostream>
#include <memory>

#define PRESS_ENTER() printf("계속 진행하려면 엔터를 누르세요.\n"); getchar();

class Data
{
public:
	Data() = default;
	explicit Data(int num)
	{
		m_num = num;
	}
	~Data() = default;

	int GetNum() const noexcept
	{
		return m_num;
	}


private:
	int m_num;
};

int main()
{
	//// share_ptr
	//// 소유권을 공유하는 스마트 포인터
	//// 소유권을 공유할수록 레퍼런스 카운트가 증가됨
	//std::shared_ptr<Data> pOldData = std::make_shared<Data>(100);
	//assert(pOldData);

	//// 일반 포인터에 대입하는 경우에는 get() 메서드 이용
	//Data* pOriginal = pOldData.get();
	//assert(pOriginal);

	//// 스마트 포인터에는 그냥 대입 가능
	//// 복사가 발생하면 레퍼런스 카운트 증가
	//std::shared_ptr<Data> pNewData = pOldData;
	//assert(pNewData);

	//printf(" pOldData의 역참조값 : %d\n", pOldData->GetNum());
	//printf("pOriginal의 역참조값 : %d\n", pOriginal->GetNum());
	//printf(" pNewData의 역참조값 : %d\n\n", pNewData->GetNum());

	//////////////////////////////////////////////////////////////////////////

	//// unique_ptr
	//// 소유권을 공유하지 않는 스마트 포인터
	//// 소유권 양도만 가능
	//std::unique_ptr<Data> pUniqueData = std::make_unique<Data>(200);
	//assert(pUniqueData);

	//// 일반 포인터에 대입하는 경우에는 get() 메서드 이용
	//// 소유권 공유가 아니라 순수 포인터만 가져오는 방법
	//Data* pOriginal = pUniqueData.get();
	//assert(pOriginal);

	//// 소유권 공유는 불가능
	////std::unique_ptr<Data> pNewUniqueData = pUniqueData;

	//// 소유권 양도는 가능
	//std::unique_ptr<Data> pNewUniqueData = std::move(pUniqueData);
	//assert(pNewUniqueData);

	//// 소유권을 양도하면 pUniqueData는 더 이상 쓸모가 없음
	////printf(" pOldData의 역참조값 : %d\n", pUniqueData->GetNum());
	//
	//printf("     pOriginal의 역참조값 : %d\n", pOriginal->GetNum());
	//printf("pNewUniqueData의 역참조값 : %d\n\n", pNewUniqueData->GetNum());

	// std::unique_ptr을 사용하다 보면
	// 안전성 검사 때문에 생성자와 소멸자에서 문제가
	// 생길 때가 있음... 그때는 생성자와 소멸자의
	// 선언 부분과 정의 부분을 분리해서 구현해야 함!
	
	PRESS_ENTER();

	return 0;
}