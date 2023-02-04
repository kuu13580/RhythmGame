#pragma once
#include "common.h"

// タイトル画面
class Title : public App::Scene {
private:

public:
	Title(const InitData& init);
	void update() override;
	void draw() const override;
};
