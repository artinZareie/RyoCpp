#include <gtest/gtest.h>
#include "../headers/stylize.hpp"
#include <string>
#include <iostream>

TEST(Terminal, StylizeApplyRedText) {
    EXPECT_EQ(std::string("\033[0;31;40mHello\033[0m"), Ryo::Terminal::Stylize::apply("Hello", Ryo::Terminal::ForeColor::RED));
}

TEST(Terminal, StylizeApplyBlackText) {
    EXPECT_EQ(std::string("\033[0;30;40mHello\033[0m"), Ryo::Terminal::Stylize::apply("Hello", Ryo::Terminal::ForeColor::BLACK));
}

TEST(Terminal, StylizeApplyRedTextOnWhiteBackground) {
    EXPECT_EQ(std::string("\033[0;31;47mHello\033[0m"), Ryo::Terminal::Stylize::apply("Hello", Ryo::Terminal::ForeColor::RED, Ryo::Terminal::BackgroundColor::WHITE));
}

TEST(Terminal, StylizeApplyBoldBlueTextOnGreenBackground) {
    EXPECT_EQ(
        Ryo::Terminal::Stylize::apply("Bold Blue Text on Green Background",
            Ryo::Terminal::Style::BOLD,
            Ryo::Terminal::ForeColor::BLUE,
            Ryo::Terminal::BackgroundColor::GREEN),
        "\033[1;34;42mBold Blue Text on Green Background\033[0m"
    );
}

TEST(Terminal, StylizeApplyWithStyleBundle) {
    Ryo::Terminal::StyleBundle customStyle(Ryo::Terminal::Style::BOLD, Ryo::Terminal::ForeColor::BLUE, Ryo::Terminal::BackgroundColor::GREEN);

    EXPECT_EQ(
        Ryo::Terminal::Stylize::apply("Custom Styled Text", customStyle),
        "\033[1;34;42mCustom Styled Text\033[0m"
    );
}
