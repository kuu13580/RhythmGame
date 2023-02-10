#pragma once
#include "common.h"

class CNoteBase {
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
	CNoteBase(Vec2 pos, int32 width, Color color);
	virtual void update(const double& /*speed = 1.0*/) {};
	virtual void draw() {};
	Vec2 getPos() { return pos_; }
	virtual Score checkCollision(const double& /*speed*/, const int32& /*border_line*/) { return None; };
};
