#include "common.h"
#include "Note.h"

CNote::CNote(Vec2 pos, int32 radius, double aspect, Color color) :
	pos_(pos), width_(radius), aspect_(aspect), color_(color), life_time_(0)
{
	note_ = Ellipse( pos_, width_, width_ * aspect_);
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
	// 判定ラインとの時間差(ms)(正：遅い、負：早い)
	double diff = ((int32)pos_.y - border_line) / (DEFAULT_SPEED * speed) * 1000;
	//
	return Abs(diff) <= PERFECT_TIME ? PERFECT
		: Abs(diff) <= GREAT_TIME ? GREAT
		: Abs(diff) <= GOOD_TIME ? GOOD
		: GOOD_TIME < diff ? OVER
		: - diff <= MISS_TIME ? MISS
		: None;
}
