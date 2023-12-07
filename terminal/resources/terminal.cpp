#include "../headers/terminal.hpp"

void Ryo::Terminal::set_noncanonical_mode() {
    struct termios new_termios;
    tcgetattr(0, &new_termios);
    new_termios.c_lflag &= ~ICANON;
    new_termios.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &new_termios);
}

void Ryo::Terminal::restore_canonical_mode() {
    struct termios new_termios;
    tcgetattr(0, &new_termios);
    new_termios.c_lflag |= ICANON;
    new_termios.c_lflag |= ECHO;
    tcsetattr(0, TCSANOW, &new_termios);
}

void Ryo::Terminal::clear_screen() {
    std::cout << "\033[H\033[J";
}
