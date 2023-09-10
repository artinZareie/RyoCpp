#include <gtest/gtest.h>
#include "../headers/stylize.hpp"
#include <string>
#include <iostream>

TEST(Terminal, StylizeApplyTests) {
    EXPECT_EQ(std::string("\033[0;31;40mHello\033[0m"), Ryo::Terminal::Stylize::apply("Hello", Ryo::Terminal::Stylize::ForeColor::RED));
    EXPECT_EQ(std::string("\033[0;30;40mHello\033[0m"), Ryo::Terminal::Stylize::apply("Hello", Ryo::Terminal::Stylize::ForeColor::BLACK));
    EXPECT_EQ(std::string("\033[0;31;47mHello\033[0m"), Ryo::Terminal::Stylize::apply("Hello", Ryo::Terminal::Stylize::ForeColor::RED, Ryo::Terminal::Stylize::BackgroundColor::WHITE));
    EXPECT_EQ(Ryo::Terminal::Stylize::apply("Bold Blue Text on Green Background",
                                Ryo::Terminal::Stylize::Style::BOLD,
                                Ryo::Terminal::Stylize::ForeColor::BLUE,
                                Ryo::Terminal::Stylize::BackgroundColor::GREEN),
                "\033[1;34;42mBold Blue Text on Green Background\033[0m");
}
