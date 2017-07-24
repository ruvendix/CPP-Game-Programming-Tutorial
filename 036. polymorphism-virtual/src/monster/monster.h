/*
 * 파일 이름 : monster.h
 * 만든 날짜 : 2017-07-24
 * 만든 사람 : Ruvendix
 *
 * 파일 설명 : 몬스터의 선언 및 정의 부분입니다.
 */

#ifndef INHERITANCE_MONSTER_H_
#define INHERITANCE_MONSTER_H_

#include <string>

namespace monster
{
	class Monster
	{
	public:
		Monster() = default;

		explicit Monster(const std::string& strName)
		{
			m_strName = strName;
		}

		~Monster() = default;

		const std::string& GetName() const noexcept
		{
			return m_strName;
		}

		void SetName(const std::string& strName)
		{
			m_strName = strName;
		}

		int Attack()
		{
			printf("%s이(가) 공격했다!\n", m_strName.c_str());
			return 0;
		}

		int Move()
		{
			printf("%s이(가) 이동했다!\n", m_strName.c_str());
			return 0;
		}

		// 상위 클래스의 기본 메서드
		virtual int UpdateAction()
		{
			Attack();
			Move();
			return 0;
		}


	private:
		// private은 하위 클래스도 접근 불가
		std::string m_strName;
	};
} // namespace monster end

#endif