#include "Fit/Tools/StringUtils.h"
#include "Tests/GTestWrapper/google_test.h"

class StringUtilsTest : public ::testing::Test {};

TEST_F(StringUtilsTest, removeSubstring) {
    std::string target("one two threeone five one");
    std::string result = mumufit::stringUtils::removeSubstring(target, "one");
    EXPECT_EQ(result, " two three five ");
}

TEST_F(StringUtilsTest, toLower) {
    std::string target("QyQz");
    EXPECT_EQ(mumufit::stringUtils::to_lower(target), "qyqz");
}
