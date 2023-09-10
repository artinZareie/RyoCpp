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

    static std::string apply(const std::string& context, ForeColor text_color);
    static std::string apply(const std::string& context, ForeColor text_color, BackgroundColor bc_color);
};

}

#endif

#endif