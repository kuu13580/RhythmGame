#include "common.h"
#include "Game.h"
#include "Note.h"
#include "Lane.h"

Game::Game(const InitData& init)
	: IScene{ init }, speed_(1.0), border_y_(Scene::Size().y - 100), delta_time_(0),
	head_(chart_.begin()), font_(Font{ 20 }), shown_judge_(None), start_judge_(-10),
	audio_(Audio{ U"src/SE/Clap01.mp3" })
{
	// 背景色設定
	Scene::SetBackground(Palette::Black);
	// レーンを設定
	for (int8 i = 0; i < NUM_LANE; i++) {
		lanes_ << CLane(300 + (Scene::Size().x / (NUM_LANE - 1) - 200) * i, 20, i);
	}
	setChart();

}

void Game::update() {
	delta_time_ += Scene::DeltaTime();
	// 譜面更新
	while (head_ != chart_.end() and head_->time <= delta_time_ * 1000) {
		lanes_.at(head_->lane).addNote();
		head_++;
	}
	// レーン更新
	for (auto& lane : lanes_) {
		lane.update(speed_, border_y_);
	}
	// 判定処理
	InputGroup input;
	for (int i = 0; i < NUM_LANE; i++) {
		input = i == 0 ? KeyF
			: i == 1 ? KeyG
			: i == 2 ? KeyH
			: i == 3 ? KeyJ
			: KeySpace;
		Score judge = lanes_.at(i).checkCollision(speed_, border_y_);
		if (judge == OVER) {
			lanes_.at(i).DeleteActiveNote();
			shown_judge_ = MISS;
			start_judge_ = delta_time_;
		}
		if (input.down()) {
			audio_.playOneShot(0.2);
			if (judge != None) {
				lanes_.at(i).DeleteActiveNote();
				shown_judge_ = judge;
				start_judge_ = delta_time_;
			}
		}

	}
}

void Game::draw() const {
	// 判定ラインの描画
	Line{ 0, border_y_, Scene::Size().x, border_y_ }.draw(Palette::White);
	// 描画
	for (auto lane : lanes_) {
		lane.draw();
	}
	// 判定の表示
	if (delta_time_ < start_judge_ + SHOW_JUDGEMENT_TIME / 1000.0) {
		String judge_text =
			shown_judge_ == PERFECT ? U"Perfect"
			: shown_judge_ == GREAT ? U"Great"
			: shown_judge_ == GOOD ? U"Good"
			: shown_judge_ == MISS ? U"MISS"
			: U"";
		font_(judge_text).drawAt(Scene::Center().x, border_y_ - 30, Palette::Yellow);
	}
}

// 譜面データを設定
void Game::setChart() {
	// デバッグではtestデータを使用(実際はファイルから読み込み)
	for (const auto& note : test) {
		chart_ << note;
	}
	head_ = chart_.begin();
}
