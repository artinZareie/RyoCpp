#include "../headers/yesno.hpp"

using namespace Ryo::Terminal;

YesNo::YesNo(const std::string &message): message(message), text_style(), selected_opt_style(ForeColor::BLACK, BackgroundColor::WHITE) {}
YesNo::YesNo(const std::string &message, const StyleBundle &style_bundle): message(message), text_style(style_bundle), selected_opt_style(ForeColor::BLACK, BackgroundColor::WHITE) {}
YesNo::YesNo(const std::string &message, const StyleBundle &style_bundle, const StyleBundle &selected_opt): message(message), text_style(style_bundle), selected_opt_style(selected_opt) {}

std::string YesNo::build_styled_msg(const bool &selected) const {
	return Stylize::apply(message, text_style) + (selected ? Stylize::apply("Yes", selected_opt_style) + Stylize::apply("No", text_style) : Stylize::apply("Yes", text_style) + Stylize::apply("No", selected_opt_style));
}

bool YesNo::fire() const {
	set_noncanonical_mode();
	
	bool choice = false;
	char key;
	std::cout << build_styled_msg(choice);

	restore_canonical_mode();		
}
