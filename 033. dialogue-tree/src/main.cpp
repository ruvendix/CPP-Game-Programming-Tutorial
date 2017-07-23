/*
 * 파일 이름 : main.cpp
 * 만든 날짜 : 2017-07-23
 * 만든 사람 : Ruvendix
 *
 * 파일 설명 : 대화 시스템을 테스트합니다.
 */

#include <iostream>

#include "common/macro.h"
#include "dialogue/dialogue.h"

int main()
{
	dialogue::DialogueTree* tree = new dialogue::DialogueTree;

	tree->Init();

	int resultFlagAdapter = tree->Excute();
	dialogue::DialougeFlag resultFlag = static_cast<dialogue::DialougeFlag>(resultFlagAdapter);

	// 플래그의 상태에 따른 결과
	switch (resultFlag)
	{
	case dialogue::DialougeFlag::END:
		printf("게임이 끝났습니다.\n");
		break;
	case dialogue::DialougeFlag::DIE:
		printf("당신은 죽었습니다...\n");
		break;
	case dialogue::DialougeFlag::SURVIVE:
		printf("당신은 살았습니다!\n");
		break;
	}

	SAFE_DELETE(tree);

	PRESS_ENTER();

	return 0;
}