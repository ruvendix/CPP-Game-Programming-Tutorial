/*
 * 파일 이름 : main.cpp
 * 만든 날짜 : 2017-07-25
 * 만든 사람 : Ruvendix
 *
 * 파일 설명 : 순수 가상 함수를 테스트합니다.
 */

#define PRESS_ENTER() printf("계속 진행하려면 엔터를 누르세요.\n"); getchar();

#include <memory>

#include "stage/stage.h"

int main()
{
	std::unique_ptr<stage::StageBase> pStageBase =
		std::make_unique<stage::StageBase>();

	pStageBase->Init();

	for (int i = 0; i < 4; ++i)
	{
		pStageBase->Update();
	}

	// Release()는 StageBase에서
	// private이므로 외부에서 접근 불가!
	// pStageBase->Release();

	PRESS_ENTER();

	return 0;
}