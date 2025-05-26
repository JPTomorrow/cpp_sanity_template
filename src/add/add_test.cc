/*
    TESTING SETUP WITH Google Test (GTest)
    This is an example test file using Google Test.

    @ TODO(Justin): deleting this file without creating another test
    file somewhere in the src/ directory may cause an error in cmake
    right now. Not a huge issue, I will fix it later. Just wanted to
    note it.

    A test file can be placed anywhere inside of the src/ directory
    or its subfolders and still be picked up by cmake and will be
    included in the tests after a build when ctest is ran.
*/

#include <gtest/gtest.h>
#include "add.h"

// Demonstrate some basic assertions.
TEST(AddTest, BasicAssertions)
{
    // EXPECT_STRNE("hello", "world");
    EXPECT_EQ(test_add(1, 2), 3);
}
