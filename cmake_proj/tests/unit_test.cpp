#include <gtest/gtest.h>
#include "division.h"
#include "multiply.h"

TEST(TestDivision, RandomChecks) {
  EXPECT_EQ(4, division(8,2));
  //EXPECT_EQ(3, division(12,3));
}

TEST(TestMultiply, RandomChecks) {
  EXPECT_EQ(16, multiply(8,2));
  //EXPECT_EQ(24, multiply(12,3));
}