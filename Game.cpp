#include "common.h"
#include "Game.h"

Game::Game(const InitData& init) : IScene{ init }, speed_(1.0), border_y_(Scene::Size().y - 100) {
	Scene::SetBackground(Palette::Black);
	notes_ << CNote(Vec2{ 300,200 }, 10, 0.5, Palette::White);
	notes_ << CNote(Vec2{ 200,200 }, 10, 0.5, Palette::Blue);
}

void Game::update() {
	for (auto& note : notes_) {
		note.update();
	}
	// 入力キー取得
	if (KeySpace.down()) {
		Print << notes_.at(0).checkCollision(speed_, border_y_);
	}
}

void Game::draw() const {
	// 判定ラインの描画
	Line{0, border_y_, Scene::Size().x, border_y_}.draw(Palette::White);
	// ノーツの描画
	for (auto note : notes_) {
		note.draw();
	}
}
