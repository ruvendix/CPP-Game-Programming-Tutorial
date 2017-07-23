/*
 * 파일 이름 : dialouge.cpp
 * 만든 날짜 : 2017-07-23
 * 만든 사람 : Ruvendix
 *
 * 파일 설명 : 대화 시스템의 정의 파일입니다.
 */

#include "dialogue.h"

#include <cassert>
#include <iostream>

const int MAX_NODE = 6;

namespace dialogue
{
	int DialogueOption::Adjust(const std::string& strSubLine,
		DialougeFlag flag, const DialougeNode* pNextNode)
	{
		m_strSubLine = strSubLine;
		m_flag = flag;

		// const 포인터로 대입 연산자를 사용하고 싶으면
		// const_cast를 이용해서 const 기능을 빼야 함!
		// 인자는 const 포인터로 넘어왔으므로 함수 내부에서는
		// 역참조를 이용해서 값을 변경할 수 없음!
		m_pNextNode = const_cast<DialougeNode*>(pNextNode);

		return 0;
	}

	DialougeNode::~DialougeNode()
	{
		for (size_t i = 0; i < m_vecOption.size(); ++i)
		{
			SAFE_DELETE(m_vecOption[i]);
		}
	}

	int DialougeNode::Insert(const std::string& strSubLine,
		DialougeFlag flag, const DialougeNode* pNextNode)
	{
		// pNextNode가 nullptr인 경우도 사용하므로
		// 이 경우에는 assert()를 사용하면 안됨!
		//assert(pNextNode != nullptr);

		DialogueOption* pDialogueOption = nullptr;

		pDialogueOption = new DialogueOption;
		assert(pDialogueOption != nullptr);

		pDialogueOption->Adjust(strSubLine, flag, pNextNode);
		m_vecOption.push_back(pDialogueOption);

		return 0;
	}

	int DialogueTree::Init()
	{
		DialougeNode* pNodeTable[MAX_NODE];

		for (int i = 0; i < MAX_NODE; ++i)
		{
			pNodeTable[i] = new DialougeNode;
			assert(pNodeTable[i] != nullptr);
		}

		// 첫 번째 대화
		pNodeTable[0]->SetMainLine("안녕~ 좋은 아침~");

		pNodeTable[0]->Insert("안녕 못함", DialougeFlag::NEXT, pNodeTable[1]);
		pNodeTable[0]->Insert("응~ 너도~", DialougeFlag::NEXT, pNodeTable[2]);
					 
		m_vecNode.push_back(pNodeTable[0]);

		//////////////////////////////////////////////////////////////////////////

		// 두 번째 대화
		pNodeTable[1]->SetMainLine("뭐가 이리 차가워!");

		pNodeTable[1]->Insert("어쩌라고!", DialougeFlag::END, nullptr);
		
		m_vecNode.push_back(pNodeTable[1]);
		
		//////////////////////////////////////////////////////////////////////////

		// 세 번째 대화
		pNodeTable[2]->SetMainLine("나... 너한테 부탁할 게 있는데...");
					 
		pNodeTable[2]->Insert("응 말해봐~", DialougeFlag::NEXT, pNodeTable[4]);
		pNodeTable[2]->Insert("돈 주면 부탁 들어줌", DialougeFlag::NEXT, pNodeTable[3]);
		
		m_vecNode.push_back(pNodeTable[2]);
		
		//////////////////////////////////////////////////////////////////////////

		// 네 번째 대화
		pNodeTable[3]->SetMainLine("이게 돈에 미쳤나! 그냥 죽어!");
					 
		pNodeTable[3]->Insert("끄아아아악~!", DialougeFlag::DIE, nullptr);

		m_vecNode.push_back(pNodeTable[3]);

		//////////////////////////////////////////////////////////////////////////

		// 다섯 번째 대화
		pNodeTable[4]->SetMainLine("이따가~ 나랑 같이 점심 먹자~!");
					 
		pNodeTable[4]->Insert("나 점심 굶을 건데?", DialougeFlag::END, nullptr);
		pNodeTable[4]->Insert("응 좋아~", DialougeFlag::NEXT, pNodeTable[5]);
		pNodeTable[4]->Insert("내가 미쳤냐! 왜 너랑 같이 먹어야 하는데?!", DialougeFlag::END, nullptr);

		m_vecNode.push_back(pNodeTable[4]);

		//////////////////////////////////////////////////////////////////////////

		// 여섯 번째 대화
		pNodeTable[5]->SetMainLine("ㅎㅎ 그러면 이따 봐~");

		pNodeTable[5]->Insert("응 그래~", DialougeFlag::SURVIVE, nullptr);

		m_vecNode.push_back(pNodeTable[5]);

		return 0;
	}

	int DialogueTree::Excute()
	{
		DialougeNode* pNode = m_vecNode[0];

		// 이전의 입력값도 이용하기 위해
		// while문 밖에서 선언
		size_t select = 0;

		while (true)
		{
			printf("미영 : %s\n", pNode->GetMainLine().c_str());

			std::vector<DialogueOption*> vecOption = pNode->GetVecDialogueOption();

			int size = vecOption.size();

			if (size != 1)
			{
				for (size_t i = 0; i < size; ++i)
				{
					printf("%d. %s\n", i + 1, vecOption[i]->GetSubLine().c_str());
				}
			}
			else
			{
				printf("%s\n", vecOption[0]->GetSubLine().c_str());
			}
			printf("\n");

			// select에서 이미 다음 대화를 결정했기 때문에
			// 다음 대화를 판단할 때는 vecOption[0]가 됨 
			// 최종 대화는 선택지가 없으므로 선택지가 하나인지 확인해야 함
			if ((vecOption.size() == 1) && (vecOption[0]->GetNextNode() == nullptr))
			{
				// enum class는 static_cast<int>로 변환해서 사용!
				return static_cast<int>(vecOption[0]->GetFlag());
			}

			// 분기 선택 부분
			// 입력하면 그때의 플래그를 검사
			printf(">> ");
			scanf("%d", &select);
			getchar(); // 개행 문자 방지

			bool bVaild = true;
			if (select <= 0 || select > vecOption.size()) bVaild = false;
			assert(bVaild != false); // assert는 구현 부분을 피해야 함!
			if (bVaild == false)
			{
				printf("입력 범위를 벗어났습니다!\n\n");
				select = 0;
				continue;
			}

			// if를 거치면 무조건 return되므로 이 경우에는 else를 안 써도 됨
			pNode = const_cast<DialougeNode*>(vecOption[select - 1]->GetNextNode());

			// 다음 대화 자체가 nullptr이면 해당되는 플래그를 반환
			if (pNode == nullptr)
			{
				// enum class는 static_cast<int>로 변환해서 사용!
				return static_cast<int>(vecOption[select - 1]->GetFlag());
			}
		}

		return 0;
	}

	int DialogueTree::Release()
	{
		for (size_t i = 0; i < m_vecNode.size(); ++i)
		{
			SAFE_DELETE(m_vecNode[i]);
		}

		return 0;
	}

} // namespace dialogue end