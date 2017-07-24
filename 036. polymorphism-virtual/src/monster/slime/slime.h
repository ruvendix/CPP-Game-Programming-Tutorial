/*
 * 파일 이름 : monster.h
 * 만든 날짜 : 2017-07-24
 * 만든 사람 : Ruvendix
 *
 * 파일 설명 : 슬라임 몬스터의 선언 및 정의 부분입니다.
 */

#ifndef INHERITANCE_MONSTER_SLIME_H_
#define INHERITANCE_MONSTER_SLIME_H_

#include "../monster.h"

namespace monster
{
	class Slime : public Monster
	{
	public:
		Slime() = default;
		using Monster::Monster;
		~Slime() = default;

		// Slime만의 메서드
		int Crawl()
		{
			printf("%s이(가) 기어가고 있다!\n", GetName().c_str());
			return 0;
		}

		// Slime의 오버라이딩
		virtual int UpdateAction()
		{
			Attack();
			Crawl();
			return 0;
		}
	};
} // namespace monster end

#endif