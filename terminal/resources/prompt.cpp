#include "../headers/prompt.hpp"

using namespace Ryo::Terminal;

Prompt::Prompt(std::string question): question(question), default_value(), is_inline(true), question_style() {}
Prompt::Prompt(std::string question, std::string default_value): question(question), default_value(default_value), is_inline(true), question_style() {}
Prompt::Prompt(std::string question, std::string default_value, bool is_inline): question(question), default_value(default_value), is_inline(is_inline), question_style() {}
Prompt::Prompt(std::string question, std::string default_value, bool is_inline, const StyleBundle &question_style): question(question), default_value(default_value), is_inline(is_inline), question_style(question_style) {}

std::string Prompt::fire() {
    set_noncanonical_mode();

    std::string user_input = default_value;
    std::cout << Stylize::apply(question, question_style);
    if (!is_inline) {
        std::cout << std::endl;
    }
    std::cout.flush();
    std::cout << user_input;
    std::cout.flush();

    char input_char;
    while (read(STDIN_FILENO, &input_char, 1) == 1 && input_char != '\n') {
        if (input_char == 127 || input_char == '\b') {
            if (!user_input.empty()) {
                user_input.pop_back();
                std::cout << "\b \b";
            }
        } else {
            user_input += input_char;
            std::cout << input_char;
        }
        std::cout.flush();
    }

    std::cout << std::endl;

    restore_canonical_mode();

    return user_input;
}
