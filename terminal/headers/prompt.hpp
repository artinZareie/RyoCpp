#ifndef PROMPT_H
#define PROMPT_H
#include <string>
#include "terminal.hpp"
#include "stylize.hpp"
#include <iostream>

#ifdef __linux__

namespace Ryo::Terminal {

class Prompt {
public:
    std::string question;
    std::string default_value;
    bool is_inline;
    StyleBundle question_style;
public:
    Prompt() = delete;
    Prompt(std::string question);
    Prompt(std::string question, std::string default_value);
    Prompt(std::string question, std::string default_value, bool is_inline);
    Prompt(std::string question, std::string default_value, bool is_inline, const StyleBundle &question_style);
    std::string fire();
};

}

#endif

#endif