#pragma once
#include "common.h"
#include "NoteBase.h"

class CLongNote : public CNoteBase {
private:
	// 描画本体
	Line longNote_;
	// 描画終了位置
	Vec2 end_pos_;
public:
	CLongNote(Vec2 s_pos, Vec2 e_pos, int32 width, Color color);
	void update(const double& speed) override;
	void draw() override { longNote_.draw(color_); }
	Score checkCollision(const double& speed, const int32& border_line) override;
};
