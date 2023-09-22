#ifndef COLORIZE_H
#define COLORIZE_H
#include <string>

#ifdef __linux__

namespace Ryo::Terminal {

/**
 * @class Stylize
 * @details Generate colorize codes for Unix-like systems.
*/
class Stylize
{
public:
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

    static std::string apply(const std::string& context, Style Style, ForeColor text_color, BackgroundColor bc_color);
    static std::string apply(const std::string& context, ForeColor text_color);
    static std::string apply(const std::string& context, BackgroundColor bc_color);
    static std::string apply(const std::string& context, Style style);
    static std::string apply(const std::string& context, ForeColor text_color, BackgroundColor bc_color);
    static std::string apply(const std::string& context, Style style, ForeColor text_color);
    static std::string apply(const std::string& context, Style style, BackgroundColor bc_color);
};

/**
 * @struct ColorBundle Holds both For color and Back color.
 * @todo UPDATE the code later to add color bundle to Stylize code, getting out the Forecolor and Backcolor enums, etc;
*/
struct ColorBundle {
    Stylize::ForeColor fcolor;
    Stylize::BackgroundColor bcolor;

    ColorBundle();
    ColorBundle(Stylize::ForeColor forecolor, Stylize::BackgroundColor backcolor);
};

}

#endif

#endif