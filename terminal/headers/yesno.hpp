#pragma once

#include <string>
#include "stylize.hpp"

#ifdef __linux__

namespace Ryo::Terminal {

class YesNo {
public:
    std::string message;
    StyleBundle text_style;
public:
    YesNo(const std::string &message);
    YesNo(const std::string &message, const StyleBundle &style_bundle);
    bool fire() const;
};

}

#endif
