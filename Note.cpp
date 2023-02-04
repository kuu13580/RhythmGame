#include "common.h"
#include "Note.h"

CNote::CNote(Vec2 pos, int32 radius, double aspect, Color color) :
	pos_(pos), radius_(radius), aspect_(aspect), color_(color), life_time_(0)
{
	note_ = Ellipse( pos_, radius_, radius_ * aspect_);
}

void CNote::update(const double& speed) {
	// ノーツ出現からの更新時間 
	life_time_ += Scene::DeltaTime();
	pos_.y = DEFAULT_NOTE_START_Y + life_time_ * DEFAULT_SPEED * speed;

	// 位置を更新
	note_.setPos(pos_.x, pos_.y);
}

// 判定ラインとの衝突判定
Score CNote::checkCollision(const double& speed, const int32& border_line) {
	// 判定ラインとの時間差(ms)
	double diff = AbsDiff(border_line, (int32)pos_.y) / (DEFAULT_SPEED * speed) * 1000;
	//
	return diff <= PERFECT_TIME ? PERFECT
		: diff <= GREAT_TIME ? GREAT
		: diff <= GOOD_TIME ? GOOD
		: diff <= MISS_TIME ? MISS
		: pos_.y > border_line ? OVER
		: None;
}
