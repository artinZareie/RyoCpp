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

namespace Ryo {
namespace Terminal {

/**
 * @struct ChoicesConfig Holds the config related to Choices class
*/
struct ChoicesConfig {
    
};

/**
 * @class Choices Provides interactive multi-choice question box for terminal.
*/
class Choices {
private:
    std::string m_prompt;
    std::vector<std::string> m_options;
private:
    void clear_menu_section(unsigned int num_options);
    void print_options(int choice);
public:
    Choices(std::string prompt, std::vector<std::string> options);
    Choices(std::string prompt, std::vector<char*> options);
    unsigned int fire();
};

}
}

#endif
#endif
