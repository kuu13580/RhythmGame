﻿#include "common.h"
#include "Game.h"
#include "Note.h"
#include "Lane.h"

Game::Game(const InitData& init)
	: IScene{ init }, speed_(1.0), border_y_(Scene::Size().y - 100), delta_time_(0)
{
	Scene::SetBackground(Palette::Black);
	for (int i = 0; i < 4; i++) {
		lanes_ << CLane(300 + (Scene::Size().x / 3 - 200) * i, 20, i);
	}
	lanes_.at(0).addNote();
	lanes_.at(1).addNote();
}

void Game::update() {
	delta_time_ += Scene::DeltaTime();
	for (auto& lane : lanes_) {
		lane.update(speed_);
	}
	if (KeyF.down()) {
		Print << lanes_.at(0).checkCollision(speed_, border_y_);
	}
	if (KeyG.down()) {
		Print << lanes_.at(1).checkCollision(speed_, border_y_);
	}
	if (KeyH.down()) {
		Print << lanes_.at(2).checkCollision(speed_, border_y_);
	}
	if (KeyJ.down()) {
		Print << lanes_.at(3).checkCollision(speed_, border_y_);
	}
}

void Game::draw() const {
	// 判定ラインの描画
	Line{ 0, border_y_, Scene::Size().x, border_y_ }.draw(Palette::White);
	// 描画
	for (auto lane : lanes_) {
		lane.draw();
	}
}