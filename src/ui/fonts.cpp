#include "fonts.h"

namespace ui
{
	Font load_font()
	{
		Font font{ LoadFontEx(ui::FONT_PATH, ui::FONT_SIZE, nullptr, ui::FONT_CODEPOINTS_COUNT) };
		
		if (!IsFontValid(font))
		{
			enigma::Log::error("Failed to load font from path: %s", ui::FONT_PATH);
			return GetFontDefault();
		}
		return font;
	}
}