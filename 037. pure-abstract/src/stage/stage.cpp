/*
 * 파일 이름 : stage.cpp
 * 만든 날짜 : 2017-07-25
 * 만든 사람 : Ruvendix
 *
 * 파일 설명 : 스테이지에 관한 내용이 정의되어있습니다.
 */

#include "stage.h"

#include <iostream>

namespace stage
{
	int StageBase::Init()
	{
		printf("스테이지 초기화!\n");
		return 0;
	}

	int StageBase::Update()
	{
		printf("스테이지 정보 갱신!\n");
		return 0;
	}

	int StageBase::Release()
	{
		printf("스테이지 소멸!\n");
		return 0;
	}
}