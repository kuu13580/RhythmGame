#include "common.h"
#include "Title.h"
#include "Game.h"

Array<NoteData>test = {
	{1000, 0, 0},
	{1500, 0, 1},
	{2000, 0, 0},
	{2000, 0, 2},
	{2500, 0, 3},
	{3000, 0, 2},
	{3500, 0, 1},
	{4000, 0, 0},
};

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
