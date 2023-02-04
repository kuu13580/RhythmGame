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
	int32 time; // 設置時間(ms)
	int32 line; // ライン
}NoteData;

// デフォルトのノーツスピード px / s
constexpr double DEFAULT_SPEED = 100.0;

// 判定時間(ms)
extern const uint32 PERFECT_TIME;
extern const uint32 GREAT_TIME;
extern const uint32 GOOD_TIME;
extern const uint32 MISS_TIME;

// 名前変えるかも
typedef enum Score {
	None,
	PERFECT,
	GREAT,
	GOOD,
	MISS,
} Score;


using App = SceneManager<State, GameData>;
