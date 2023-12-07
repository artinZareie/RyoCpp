#pragma once
#include <string>

#ifdef __linux__

namespace Ryo::Terminal {

/**
 * @enum ForeColor
 * @brief Enumeration of foreground text colors for styling.
 *
 * ForeColor defines ANSI codes for foreground color that can be used to colorize
 * the text for ANSI-supported terminals, such as Linux, Unix, etc.
 */
enum class ForeColor {
    DEFAULT = 0,
    BLACK = 30,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};

/**
 * @enum BackgroundColor
 * @brief Enumeration of background colors using ANSI escape codes.
 *
 * `BackgroundColor` defines background colors for styling text in a terminal using
 * ANSI escape codes. Each enumerator corresponds to a specific background color.
 */
enum class BackgroundColor {
    DEFAULT = 40,
    BLACK = 40,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};

/**
 * @enum Style
 * @brief Enumeration of text styles using ANSI escape codes.
 *
 * `Style` defines text styles that can be applied to text in a terminal using
 * ANSI escape codes. Each enumerator corresponds to a specific text style.
 */
enum class Style {
    DEFAULT = 0,
    BOLD = 1,
    DIM = 2,
    ITALIC = 3,
    UNDERLINE = 4,
    BLINK = 5,
    INVERT = 7,
    HIDDEN = 8
};

/**
 * @struct ColorBundle Holds both For color and Back color.
 * @todo UPDATE the code later to add color bundle to Stylize code, getting out the Forecolor and Backcolor enums, etc;
*/
struct StyleBundle {
    ForeColor fcolor;
    BackgroundColor bcolor;
    Style style;

    StyleBundle();
    StyleBundle(ForeColor forecolor);
    StyleBundle(ForeColor forecolor, BackgroundColor backcolor);
    StyleBundle(Style stlye, ForeColor forecolor, BackgroundColor backcolor);
};

/**
 * @class Stylize
 * @details Generate stylized codes for Unix-like systems.
*/
class Stylize
{
public:
    static std::string apply(const std::string& context, const Style &Style, const ForeColor &text_color, const BackgroundColor &bc_color);
    static std::string apply(const std::string& context, const ForeColor &text_color);
    static std::string apply(const std::string& context, const BackgroundColor &bc_color);
    static std::string apply(const std::string& context, const Style &style);
    static std::string apply(const std::string& context, const ForeColor &text_color, const BackgroundColor &bc_color);
    static std::string apply(const std::string& context, const Style &style, const ForeColor &text_color);
    static std::string apply(const std::string& context, const Style &style, const BackgroundColor &bc_color);
    static std::string apply(const std::string& context, const StyleBundle &style);

    Stylize() = delete;
};

}

#endif
