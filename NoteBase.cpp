#include "common.h"
#include "NoteBase.h"

CNoteBase::CNoteBase(Vec2 pos, int32 width, Color color) :
	pos_(pos), width_(width), color_(color), life_time_(0)
{
}
