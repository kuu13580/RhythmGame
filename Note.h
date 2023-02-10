#pragma once
#include "common.h"

class CNote {
private:
	// 描画本体
	Ellipse note_;
	// 縦横比
	double aspect_;
protected:
	// 色
	Color color_;
	// 描画位置
	Vec2 pos_;
	// 大きさ(横)
	int32 width_;
	// 生成時間
	double life_time_;
public:
	CNote(Vec2 pos, int32 width, double aspect, Color color);
	~CNote() {}
	void update(const double& speed = 1.0) ;
	void draw() { note_.draw(color_); }
	Vec2 getPos() { return pos_; }
	Score checkCollision(const double& speed, const int32& border_line);
};
