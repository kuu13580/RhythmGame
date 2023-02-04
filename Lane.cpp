#include "common.h"
#include "Lane.h"
#include "Note.h"

CLane::CLane(int32 pos_x, int32 width, int8 no) :
	pos_x_(pos_x), width_(width), no_(no), active_note_(0), num_active_note_(0)
{
	// 最大数のノーツを準備
	notes_.reserve(MAX_NOTES_OF_LANE);
	for (int32 i = 0; i < MAX_NOTES_OF_LANE; i++) {
		notes_ << CNote(Vec2{ pos_x_, -100 }, NOTE_SIZE, NOTE_ASPECT, Palette::White);
	}
}

// ノーツ追加
void CLane::addNote() {
	if (num_active_note_ >= MAX_NOTES_OF_LANE) return;
	notes_.at((active_note_ + num_active_note_ + 1) % MAX_NOTES_OF_LANE) = CNote(Vec2{ pos_x_, DEFAULT_NOTE_START_Y }, NOTE_SIZE, NOTE_ASPECT, Palette::White);
	num_active_note_++;
}

void CLane::update(const double& speed, const int32& border_line) {
	// ノーツを更新
	for (int32 count = 0, i = active_note_; count < num_active_note_; count++) {
		notes_.at(i).update(speed);
		i = (i + 1) % MAX_NOTES_OF_LANE;
	}
}

void CLane::draw() {
	// デバッグ：ライン描画
	Line{ pos_x_, 0, pos_x_, Scene::Size().y }.draw(Palette::White);
	// ノーツを描画
	for (int32 count = 0, i = active_note_; count < num_active_note_; count++) {
		notes_.at(i).draw();
		i = (i + 1) % MAX_NOTES_OF_LANE;
	}
}

Score CLane::checkCollision(const double& speed, const int32& border_line) {
	// 判定ライン判定
	return notes_.at(active_note_).checkCollision(speed, border_line);
}

// 先頭のノーツを消す
void CLane::DeleteActiveNote() {
	active_note_++;
	active_note_ %= MAX_NOTES_OF_LANE;
	num_active_note_--;
}
