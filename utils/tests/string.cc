#include <gtest/gtest.h>
#include "../headers/string.hpp"
#include <string>
#include <vector>

TEST(Utils_String, Null_Split) {
    std::string subject = "Hello?";
    std::vector<std::string> tokens = Ryo::Utils::String::split(subject, ',');

    EXPECT_EQ(tokens.size(), 1);
    EXPECT_EQ(tokens[0], subject);
}

TEST(Utils_String, Char_Split) {
    std::string subject = "Hello, World, Why";
    std::vector<std::string> tokens = Ryo::Utils::String::split(subject, ',');

    EXPECT_EQ(tokens.size(), 3);
    EXPECT_EQ(tokens[0], "Hello");
    EXPECT_EQ(tokens[1], " World");
    EXPECT_EQ(tokens[2], " Why");
}

TEST(Utils_String, String_Split) {
    std::string subject = "One upon a timedelMacbook";
    std::vector<std::string> tokens = Ryo::Utils::String::split(subject, "del");

    EXPECT_EQ(tokens.size(), 2);
    EXPECT_EQ(tokens[0], "One upon a time");
    EXPECT_EQ(tokens[1], "Macbook");
}
