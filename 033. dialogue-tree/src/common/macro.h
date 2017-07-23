/*
 * 파일 이름 : macro.h
 * 만든 날짜 : 2017-07-23
 * 만든 사람 : Ruvendix
 *
 * 파일 설명 : 공통으로 사용하는 매크로가 정의되어있습니다.
 */

#ifndef DIALOGUETREE_MACRO_H_
#define DIALOGUETREE_MACRO_H_

#include <iostream>

#define SAFE_DELETE(ptr) if (ptr != nullptr)\
                         {\
                             delete ptr;\
                             ptr = nullptr;\
                         }

#define SAFE_DELETE_ARRAY(arrayPtr) if (arrayPtr != nullptr)\
                                    {\
                                        delete[] arrayPtr;\
                                        arrayPtr = nullptr;\
                                    }

#define PRESS_ENTER() printf("계속 진행하려면 엔터를 누르세요.\n"); getchar();

#endif