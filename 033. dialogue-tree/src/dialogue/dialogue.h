/*
 * 파일 이름 : dialouge.h
 * 만든 날짜 : 2017-07-23
 * 만든 사람 : Ruvendix
 *
 * 파일 설명 : 대화 시스템의 헤더 파일입니다.
 */

#ifndef DIALOGUETREE_DIALOGUE_H_
#define DIALOGUETREE_DIALOGUE_H_

#include <string>
#include <vector>

#include "../common/macro.h"

namespace dialogue
{
	enum class DialougeFlag : int
	{
		SURVIVE,
		DIE,
		NEXT,
		END,
		NONE,
	};
} // namespace dialogue end

namespace dialogue
{
	class DialougeNode;
} // namespace dialogue end

namespace dialogue
{
	class DialogueOption
	{
	public:
		// 바로 생성자에서 처리해도 되지만
		// const_cast를 설명하기 위해 일부러 다른 메서드를 이용함!
		DialogueOption()  = default;
		~DialogueOption() = default;

		// 일반적으로 포인터는 값을 변경할 때 사용하지만
		// 예외적으로 변경되면 안되는 포인터를 넘길 때는
		// const 포인터를 사용해야 함!
		int Adjust(const std::string& strSubLine,
			DialougeFlag flag, const DialougeNode* pNextNode);

		const std::string& GetSubLine() const noexcept
		{
			return m_strSubLine;
		}

		DialougeFlag GetFlag() const noexcept
		{
			return m_flag;
		}

		const DialougeNode* GetNextNode() const noexcept
		{
			return m_pNextNode;
		}


	private:
		std::string  m_strSubLine;
		DialougeFlag m_flag;

		// 다음 대화 노드가 필요한데...
		// 대화 노드는 밑에서 정의했으므로
		// 전방 선언이 필요함!
		// 전방 선언은 포인터, 매개변수에서 사용 가능
		DialougeNode* m_pNextNode;
	};

	class DialougeNode
	{
	public:
		DialougeNode() = default;
		~DialougeNode();

		int SetMainLine(const std::string& strMainLine)
		{
			m_strMainLine = strMainLine;
			return 0;
		}

		const std::string& GetMainLine() const noexcept
		{
			return m_strMainLine;
		}

		const std::vector<DialogueOption*>& GetVecDialogueOption() const noexcept
		{
			return m_vecOption;
		}

		int Insert(const std::string& strSubLine,
			DialougeFlag flag, const DialougeNode* pNextNode);


	private:
		std::string m_strMainLine;
		std::vector<DialogueOption*> m_vecOption;
	};

	class DialogueTree
	{
	public:
		DialogueTree() = default;
		~DialogueTree()
		{
			Release();
		}

		// 이렇게 자주 사용될 것 같은 메서드는
		// 인터페이스를 따로 만들고 그걸 이용하는 게 더 좋음!
		// 하지만 상속을 알아야 하므로 여기서는 생략!
		int Init();
		int Excute();


	private:
		int Release();

		std::vector<DialougeNode*> m_vecNode;
	};
} // namespace dialogue end

#endif