#include "../headers/stylize.hpp"

using namespace Ryo::Terminal;

#ifdef __linux__

std::string Stylize::apply(const std::string& context, Stylize::Style style, Stylize::ForeColor text_color, Stylize::BackgroundColor bc_color) {
    return "\033[" + std::to_string(static_cast<int>(style)) + ";" + std::to_string(static_cast<int>(text_color)) + ";" + std::to_string(static_cast<int>(bc_color)) + "m" + context + "\033[0m";
}

std::string Stylize::apply(const std::string& context, ForeColor text_color) {
    return apply(context, Style::DEFAULT, text_color, BackgroundColor::DEFAULT);
}

std::string Stylize::apply(const std::string& context, BackgroundColor bc_color) {
    return apply(context, Style::DEFAULT, ForeColor::DEFAULT, bc_color);
}

std::string Stylize::apply(const std::string& context, Style style) {
    return apply(context, style, ForeColor::DEFAULT, BackgroundColor::DEFAULT);
}

std::string Stylize::apply(const std::string& context, ForeColor text_color, BackgroundColor bc_color) {
    return apply(context, Style::DEFAULT, text_color, bc_color);
}

std::string Stylize::apply(const std::string& context, Style style, ForeColor text_color) {
    return apply(context, style, text_color, BackgroundColor::DEFAULT);
}

std::string Stylize::apply(const std::string& context, Style style, BackgroundColor bc_color) {
    return apply(context, style, ForeColor::DEFAULT, bc_color);
}

#endif