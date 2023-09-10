#include <gtest/gtest.h>
#include "../headers/colorize.hpp"
#include <string>

TEST(TerminalColorize, Red) {
    ASSERT_EQ(std::string("\033[31mHello\033[0m"), Ryo::Terminal::Colorize::apply("Hello", Ryo::Terminal::Colorize::ForeColor::RED));
}

TEST(TerminalColorize, Black) {
    ASSERT_EQ(std::string("\033[30mHello\033[0m"), Ryo::Terminal::Colorize::apply("Hello", Ryo::Terminal::Colorize::ForeColor::BLACK));
}

TEST(TerminalColorize, RedInWhite) {
    ASSERT_EQ(std::string("\033[31;47mHello\033[0m"), Ryo::Terminal::Colorize::apply("Hello", Ryo::Terminal::Colorize::ForeColor::RED, Ryo::Terminal::Colorize::BackgroundColor::WHITE));
}
