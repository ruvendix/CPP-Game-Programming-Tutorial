/*
 * 파일 이름 : monster.h
 * 만든 날짜 : 2017-07-24
 * 만든 사람 : Ruvendix
 *
 * 파일 설명 : 거미 몬스터의 선언 및 정의 부분입니다.
 */

#ifndef INHERITANCE_MONSTER_SPIDER_H_
#define INHERITANCE_MONSTER_SPIDER_H_

#include "../monster.h"

namespace monster
{
	class Spider : public Monster
	{
	public:
		Spider() = default;
		using Monster::Monster;
		~Spider() = default;

		// Spider만의 메서드
		int Climb()
		{
			printf("%s이(가) 기어오르고 있다!\n", GetName().c_str());
			return 0;
		}

		// Spider의 오버라이딩
		virtual int UpdateAction()
		{
			Attack();
			Climb();
			return 0;
		}
	};
} // namespace monster end

#endif