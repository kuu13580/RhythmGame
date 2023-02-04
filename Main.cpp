#include "common.h"
#include "Title.h"
#include "Game.h"

const uint32 PERFECT_TIME = 50;
const uint32 GREAT_TIME = 100;
const uint32 GOOD_TIME = 200;
const uint32 MISS_TIME = 500;

void Main()
{
	App manager;
	manager.add<Title>(State::Title);
	manager.add<Game>(State::Game);

	manager.init(State::Game);

	while (System::Update())
	{
		if (not manager.update())
		{
			break;
		}
	}
}
