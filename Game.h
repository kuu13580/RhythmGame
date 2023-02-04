#pragma once
#include "common.h"
#include "Note.h"

class CNote;

class Game : public App::Scene {
private:
	Array<CNote> notes_;
	// 譜面スピード
	double  speed_;
	// 判定ライン
	int32 border_y_;
public:
	Game(const InitData& init);
	void update() override;
	void draw() const override;
};
