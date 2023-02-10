#include "common.h"
#include "LongNote.h"

CLongNote::CLongNote(Vec2 s_pos, Vec2 e_pos, int32 width, Color color)
	: CNoteBase(s_pos, width, color), end_pos_(e_pos)
{

}

void CLongNote::update(const double& speed) {

}

Score checkCollision(const double& speed, const int32& border_line) {

}
