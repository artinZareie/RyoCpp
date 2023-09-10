#include <gtest/gtest.h>
#include "../include/ryo.hpp"

TEST(Ryo, VersionCheck) {
    EXPECT_STREQ("0.0.1", Ryo::version());
}
