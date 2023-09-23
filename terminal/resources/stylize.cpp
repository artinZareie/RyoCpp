#include "../headers/stylize.hpp"

using namespace Ryo::Terminal;

#ifdef __linux__

StyleBundle::StyleBundle(): fcolor(ForeColor::DEFAULT), bcolor(BackgroundColor::DEFAULT), style(Style::DEFAULT) {}
StyleBundle::StyleBundle(ForeColor forecolor): fcolor(forecolor), bcolor(BackgroundColor::DEFAULT), style(Style::DEFAULT) {}
StyleBundle::StyleBundle(ForeColor forecolor, BackgroundColor backcolor): fcolor(forecolor), bcolor(backcolor), style(Style::DEFAULT) {}
StyleBundle::StyleBundle(Style style, ForeColor forecolor, BackgroundColor backcolor): fcolor(forecolor), bcolor(backcolor), style(style) {}

std::string Stylize::apply(const std::string& context, Style style, ForeColor text_color, BackgroundColor bc_color) {
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

std::string Stylize::apply(const std::string& context, StyleBundle style) {
    return apply(context, style.style, style.fcolor, style.bcolor);
}

#endif