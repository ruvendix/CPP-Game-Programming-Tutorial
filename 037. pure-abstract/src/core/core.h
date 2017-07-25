/*
 * 파일 이름 : core.h
 * 만든 날짜 : 2017-07-25
 * 만든 사람 : Ruvendix
 *
 * 파일 설명 : 여러 클래스에서 사용하는 공통 메서드가 선언되어있습니다.
 */

#ifndef PUREABSTRACT_CORE_H_	
#define PUREABSTRACT_CORE_H_

namespace core
{
	// 추상 클래스로 선언
	// 추상 클래스란 실체화할 수 없는 클래스를 말함
	// 순수 가상 함수가 하나라도 있으면 추상 클래스로 인정하지만
	// abstract 예약어를 사용하면 무조건 추상 클래스로 인정
	// 추상 클래스에도 생성자와 소멸자가 존재하지만
	// new 또는 외부에서 실체화하는 것은 불가능
	class CoreInterface abstract
	{
	public:
		CoreInterface()          = default;
		virtual ~CoreInterface() = default;

		// 순수 가상 함수
		// 선언 및 정의는 가능하지만
		// 하위 클래스에서는 무조건 재정의해야 함!
		virtual int Init()    = 0;
		virtual int Release() = 0;

		// Update()는 매 프레임마다 호출되는 함수를 뜻함
		// Unity에는 아예 Update() 함수 자체가 존재함
		virtual int Update() { return 0; }

		// 추상 클래스에는 무조건 순수 가상 함수만
		// 존재하라는 법은 없음. 물론 순수 가상 함수만
		// 존재하도록 설계하면 가독성이 좋아짐
	};
} // namespace core end

#endif