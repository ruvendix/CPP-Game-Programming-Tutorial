/*
 * 파일 이름 : stage.h
 * 만든 날짜 : 2017-07-25
 * 만든 사람 : Ruvendix
 *
 * 파일 설명 : 스테이지에 관한 내용이 선언되어있습니다.
 */

#ifndef PUREABSTRACT_STAGE_H_	
#define PUREABSTRACT_STAGE_H_

#include "../core/core.h"

namespace stage
{
	class StageBase : public core::CoreInterface
	{
	public:
		StageBase() = default;
		virtual ~StageBase()
		{
			Release();
		}		

		// 순수 가상 함수는
		// 무조건 오버라이딩해야 함!
		// 안 그러면 컴파일 오류가 발생!
		virtual int Init() override;

		// 일반 가상 함수는
		// 무조건 오버라이딩할 필요는 없음
		// 필요에 따라 오버라이딩하면 됨
		virtual int Update() override;


	private:
		// 인터페이스는 public이지만
		// 실체 클래스에서는 private으로도 사용 가능!
		virtual int Release() override;
	};
}

#endif