#include <gtest/gtest.h>
#include "test_code.cpp"

namespace {
    TEST(CheckNumberRange, InvalidSides) {
        EXPECT_EQ(0, checkNumberRange(-1));
        EXPECT_EQ(1, checkNumberRange(50));
        EXPECT_EQ(0, checkNumberRange(101));
    }
}

