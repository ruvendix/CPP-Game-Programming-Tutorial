/*
 * vector2.h
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * vector2.h는 Vector2 클래스가 선언 및 정의되어있습니다.
 * 인라인 형식으로 되어있으므로 참고하시길 바랍니다.
 */

#ifndef ASCIIROGUELIKE_VECTOR2_H_
#define ASCIIROGUELIKE_VECTOR2_H_

// 좌표 정보를 2개 갖는 클래스
class Vector2
{
public:
	Vector2() : x_(0), y_(0) { }
	Vector2(int x, int y) : x_(x), y_(y) { }

	// get 메서드
	int get_x() const { return x_; }
	int get_y() const { return y_; }

	// set 메서드
	void set_x(int x) { x_ = x; }
	void set_y(int y) { y_ = y; }

protected:
private:
	int x_; // x좌표(열 정보)
	int y_; // y좌표(행 정보)
};

#endif