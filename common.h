#pragma once
#include <Siv3D.hpp>

// シーン名
enum class State
{
	Title,
	Game,
};

// 共有するデータ
struct GameData
{

};

// ノーツのデータ
typedef struct NoteData {
	uint32 time; // 設置時間(ms)
	int8 lane; // レーン
	bool operator>(const NoteData &another) {
		return this->time == another.time ? this->lane > another.lane : this->time > another.time;
	}
}NoteData;

//========定数定義(後々Excel等でいじれるように改良)==========

// デフォルトのノーツスピード px / s
constexpr double DEFAULT_SPEED = 100.0;

// 判定時間(ms)
constexpr uint32 PERFECT_TIME = 50;
constexpr uint32 GREAT_TIME = 100;
constexpr uint32 GOOD_TIME = 200;
constexpr uint32 MISS_TIME = 500;

// ノーツ初期出現y座標
constexpr uint32 DEFAULT_NOTE_START_Y = 100;

// レーンの最大ノーツ数
constexpr uint32 MAX_NOTES_OF_LANE = 20;

// ノーツ情報
constexpr uint32 NOTE_SIZE = 20;
constexpr double NOTE_ASPECT = 0.5;

// 判定表示時間(ms)
constexpr uint32 SHOW_JUDGEMENT_TIME = 1000;

// テスト用譜面データ
extern Array<NoteData> test;

// 名前変えるかも
typedef enum Score {
	None,
	PERFECT,
	GREAT,
	GOOD,
	MISS,
	OVER,
} Score;


using App = SceneManager<State, GameData>;
