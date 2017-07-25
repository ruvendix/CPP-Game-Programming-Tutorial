/*
 * 파일 이름 : main.cpp
 * 만든 날짜 : 2017-07-25
 * 만든 사람 : Ruvendix
 *
 * 파일 설명 : IOManger의 정의 부분입니다.
 */

#include "IOManager.h"

namespace mgr
{
	// static 필드를 초기화하는 방법
	std::string IOManager::m_strLastFileName = "NoFileName";

	// static 메서드는 그냥 일반 메서드처럼 정의해도 됨
	int IOManager::AppendStringToFile(const std::string& strFileName, const std::string& strText)
	{
		FILE* pFile = fopen(strFileName.c_str(), "at");
		assert(pFile != nullptr);

		if (pFile == nullptr) perror("파일 스트림 생성 실패!");

		fprintf(pFile, "%s\n", strText.c_str());

		fclose(pFile);

		m_strLastFileName = strFileName;

		return 0;
	}
}