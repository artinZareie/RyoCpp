#include "../headers/yesno.hpp"

using namespace Ryo::Terminal;

YesNo::YesNo(const std::string &message): message(message), text_style() {}
YesNo::YesNo(const std::string &message, const StyleBundle &style_bundle): message(message), text_style(style_bundle) {}

bool YesNo::fire() const {
    
}
