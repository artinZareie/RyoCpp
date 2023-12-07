#pragma once

/**
 * @details Unix-like specified directives.
*/
#ifdef __linux__

#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <cstdio>
namespace Ryo::Terminal {

/**
 * @fn Set non-Canonical mode
 * @details Puts Unix-like terminal in non-canonical mode
*/
void set_noncanonical_mode();

/**
 * @fn Restore Canonical mode
 * @details Puts Unix-like systems terminal in Canoncial mode.
*/
void restore_canonical_mode();

/**
 * @fn clearscreen
 * @details Clears a Unix terminal screen
*/
void clear_screen();

/**
 * @fn write_line
 * @details a helpler for `std::cout << x << std::endl;`
*/
template <typename T>
inline void write_line (T x) {
    std::cout << x << std::endl;
}


/**
 * @fn newline
 * @details a helpler for `std::cout << std::endl;`
*/
inline void newline() {
    std::cout << std::endl;
}

}

#endif