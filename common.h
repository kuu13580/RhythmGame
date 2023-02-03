#pragma once
#include "stdafx.h"

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
constexpr double DEFAULT_SPEED = 100;


using App = SceneManager<State, GameData>;
