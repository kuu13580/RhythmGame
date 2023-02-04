#include "common.h"
#include "Title.h"
#include "Game.h"

Array<NoteData>test = {
	{1000, 0},
	{1500, 1},
	{2000, 2},
	{2500, 3},
	{3000, 2},
	{3500, 1},
	{4000, 0},
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
