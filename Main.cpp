#include "common.h"
#include "Title.h"
#include "Game.h"

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
