#pragma once
#include "common.h"
#include "NoteBase.h"

class CNote : public CNoteBase {
private:
	// 描画本体
	Ellipse note_;
	// 縦横比
	double aspect_;
public:
	CNote(Vec2 pos, int32 width, double aspect, Color color);
	void update(const double& speed) override;
	void draw() override { note_.draw(color_); }
	Score checkCollision(const double& speed, const int32& border_line) override;
};
