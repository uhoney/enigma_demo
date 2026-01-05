#include "layout.h"

namespace ui
{
	void draw_background()
	{
		DrawRectangleRec({ CASE_OUTLINE.x, CASE_OUTLINE.y, CASE_OUTLINE.z, CASE_OUTLINE.w }, BEIGE);
		DrawRectangleRec({ CASE_INSIDE.x, CASE_INSIDE.y, CASE_INSIDE.z, CASE_INSIDE.w }, DARKGRAY);
	}
}