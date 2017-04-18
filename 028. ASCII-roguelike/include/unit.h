/*
 * unit.h
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 C++ 게임 프로그래밍 튜토리얼을 위한 파일입니다.
 * 경우에 따라서는 C++11 이상의 내용도 포함될 수 있습니다.
 * 참고로 이 파일은 구글 코딩 가이드를 따릅니다.
 *
 * unit.h는 Unit 클래스가 선언되어있습니다.
 * 인라인 형식도 있으므로 참고하시길 바랍니다.
 * Unit 클래스는 게이머와 적들의 공통 부분이 포함되어있습니다.
 * 원래는 상속을 이용해야 하지만 여기서는 포함된 방식으로 구현합니다.
 */

#ifndef ASCIIROGUELIKE_UNIT_H_
#define ASCIIROGUELIKE_UNIT_H_

 // 새로 만든 헤더 파일끼리는 위치 공유
#include "vector2.h"

// 게이머와 적들의 공통 부분을 포함한 클래스
class Unit
{
public:
	Unit() : pos_(0, 0), life_(0), atk_(0), def_(0), exp_(0), shape_('0') { }
	Unit(int x, int y, int life, int atk, int def, int exp, char shape)
		: pos_(x, y), life_(life), atk_(atk), def_(def),
		  exp_(exp), shape_(shape) { }

	// 유닛 정보 출력
	void ShowUnitInfo();

	// get 메서드
	Vector2 get_pos() const { return pos_; }
	int get_life() const { return life_; }
	int get_atk() const { return atk_; }
	int get_def() const { return def_; }
	int get_exp() const { return exp_; }
	char get_shape() const { return shape_; }

	// set 메서드
	void set_pos(int x, int y) { pos_.set_x(x); pos_.set_y(y); }
	void set_pos(Vector2 &pos) { pos_ = pos; }
	void set_life(int life) { life_ = life; }
	void set_atk(int atk)  { atk_ = atk; }
	void set_def(int def) { def_ = def; }
	void set_exp(int exp) { exp_ = exp; }
	void set_shape(char shape) { shape_ = shape; }
protected:
private:
	Vector2 pos_; // 좌표
	int life_;    // 생명력
	int atk_;     // 공격력(attack)
	int def_;     // 방어력(defense)
	int exp_;     // 경험치(experience)
	char shape_;  // 모양
};

#endif