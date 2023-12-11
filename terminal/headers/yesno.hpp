#pragma once

#include <string>
#include "stylize.hpp"
#include "terminal.hpp"

#ifdef __linux__

namespace Ryo::Terminal {

class YesNo {
public:
    std::string message;
    StyleBundle text_style;
	StyleBundle selected_opt_style;
public:
    YesNo(const std::string &message);
    YesNo(const std::string &message, const StyleBundle &style_bundle);
	YesNo(const std::string &message, const StyleBundle &style_bundle, const StyleBundle &selected_style);
    bool fire() const;
private:
	std::string build_styled_msg(const bool &selected) const;
};

}

#endif
