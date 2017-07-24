/*
 * 파일 이름 : main.cpp
 * 만든 날짜 : 2017-07-24
 * 만든 사람 : Ruvendix
 *
 * 파일 설명 : 상속을 테스트합니다.
 */

#include <iostream>
#include <memory>

#include "monster/spider/spider.h"

#define PRESS_ENTER() printf("계속 진행하려면 엔터를 누르세요.\n"); getchar();

int main()
{
	std::unique_ptr<monster::Spider> pSpider = std::make_unique<monster::Spider>("거미");

	pSpider->Attack();
	pSpider->Move();
	pSpider->Climb();

	PRESS_ENTER();

	return 0;
}