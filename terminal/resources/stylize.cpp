#include "../headers/stylize.hpp"

using namespace Ryo::Terminal;

#ifdef __linux__

std::string Stylize::apply(const std::string& context, Stylize::ForeColor text_color) {
    return "\033[" + std::to_string(static_cast<int>(text_color)) + "m" + context +  "\033[0m";
}

std::string Stylize::apply(const std::string& context, Stylize::ForeColor text_color, Stylize::BackgroundColor bc_color) {
    return "\033[" + std::to_string(static_cast<int>(text_color)) + ";" + std::to_string(static_cast<int>(bc_color)) + "m" + context + "\033[0m";
}

#endif