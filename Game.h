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
	// ノーツ情報(時間ms)
	Array<NoteData> chart_;
	// 譜面読み出し用イテレータ
	Array<NoteData>::iterator head_;
public:
	Game(const InitData& init);
	void update() override;
	void draw() const override;
	// 譜面データをレーンに設定
	void setChart();
};
