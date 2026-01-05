#include "fonts.h"

namespace ui
{
	Font load_font()
	{
		Font font{ LoadFontEx(ui::FONT_PATH, ui::FONT_SIZE, NULL, ui::FONT_CODEPOINTS_COUNT) };
		
		if (!IsFontValid(font))
		{
			TraceLog(LOG_ERROR, "Failed to load font from path: %s", ui::FONT_PATH);
			return GetFontDefault();
		}
		return font;
	}
}