/*
 * 파일 이름 : main.cpp
 * 만든 날짜 : 2017-07-24
 * 만든 사람 : Ruvendix
 *
 * 파일 설명 : 상속을 테스트합니다.
 */

#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

#include "monster/spider/spider.h"
#include "monster/slime/slime.h"

#define PRESS_ENTER() printf("계속 진행하려면 엔터를 누르세요.\n"); getchar();

int main()
{
	// 상위 클래스의 포인터를 저장한다고 선언
	// STL에 스마트 포인터를 사용할 때는 shard_ptr이 좋음!
	// unique_ptr을 사용하면 소유권 문제 때문에 꼬일 수가 있음...
	std::vector<std::shared_ptr<monster::Monster>> vecMonster;

	vecMonster.push_back(std::make_shared<monster::Spider>("거미"));
	vecMonster.push_back(std::make_shared<monster::Spider>("슬라임"));

	while (true)
	{
		// Range Based For문
		for (std::shared_ptr<monster::Monster> i : vecMonster)
		{
			assert(i != nullptr);
			i->UpdateAction();
		}

		PRESS_ENTER();
	}

	return 0;
}