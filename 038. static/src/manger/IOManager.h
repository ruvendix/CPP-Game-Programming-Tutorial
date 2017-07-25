/*
 * 파일 이름 : main.cpp
 * 만든 날짜 : 2017-07-25
 * 만든 사람 : Ruvendix
 *
 * 파일 설명 : IOManger의 선언 부분입니다.
 */

#ifndef STATIC_IOMANGER_H_
#define STATIC_IOMANGER_H_

#include <cassert>
#include <iostream>
#include <string>

namespace mgr
{
	class IOManager
	{
	public:
		IOManager()  = default;
		~IOManager() = default;

		// 여러 객체가 공유하는 메서드가 필요하다면
		// static으로 선언하면 됨!
		static int AppendStringToFile(const std::string& strFileName,
			const std::string& strText);

		// static 필드를 가져올 때는 static 메서드를 통해서 가져오는 게 좋음!
		// 일반 메서드로도 가능하긴 하지만 static의 의미가 없음
		static const std::string& GetLastFileName() noexcept
		{
			return m_strLastFileName;
		}

		// 여러 객체가 공유하는 필드가 필요하다면
		// static으로 선언하면 됨!
		// 다만 static 필드는 초기화를 주의해야 함!
		static std::string m_strLastFileName;
	};
} // namespace mgr end

#endif