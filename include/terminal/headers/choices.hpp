#ifndef CHOICE_H
#define CHOICE_H
#ifdef __linux__

#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <cstdio>
#include <vector>
#include "terminal.hpp"
#include "stylize.hpp"

namespace Ryo::Terminal {

/**
 * @struct ChoicesConfig Holds the config related to Choices class
*/
struct ChoicesConfig {
    StyleBundle selected_style;
    StyleBundle other_style;
    std::string selected_speciefier;

    ChoicesConfig();
};

/**
 * @class Choices Provides interactive multi-choice question box for terminal.
*/
class Choices {
private:
    std::string m_prompt;
    std::vector<std::string> m_options;
public:
    ChoicesConfig config;
private:
    void clear_menu_section(unsigned int num_options);
    void print_options(int choice);
public:
    Choices(std::string prompt, std::vector<std::string> options);
    Choices(std::string prompt, std::vector<char*> options);
    Choices(std::string prompt, std::vector<std::string> options, ChoicesConfig config);
    Choices(std::string prompt, std::vector<char*> options, ChoicesConfig config);
    void configure(ChoicesConfig config);
    unsigned int fire();
};

}

#endif
#endif
