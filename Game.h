#pragma once
#include "common.h"
#include "Lane.h"

class CLane;

class Game : public App::Scene {
private:
	// 譜面スピード
	double  speed_;
	// 判定ライン高さ
	int32 border_y_;
	// レーン
	Array<CLane> lanes_;
	// 開始からの時間(s)
	double delta_time_;
public:
	Game(const InitData& init);
	void update() override;
	void draw() const override;
};
