#pragma once
#include "common.h"
#include "Note.h"

class CNote;

class CLane {
private:
	// 判定ライン上中心x座標
	int32 pos_x_;
	// 幅
	int32 width_;
	// レーンナンバー(左から0,1,...)
	int32 no_;
	// ノーツ
	Array<CNote> notes_;
	// 有効なノーツ先頭
	int32 active_note_;
	// 有効なノーツ数
	int32 num_active_note_;
public:
	// コンストラクタ
	CLane(int32 pos_x, int32 width, int32 no);
	// ノーツ追加
	void addNote();
	void update(const double& speed, const int32& border_line);
	void draw();
	// 判定
	Score checkCollision(const double& speed, const int32& border_line);
	// 先頭のノーツを消す
	void DeleteActiveNote();
};
