#include <gtest/gtest.h>

#include <string>

/**
 * This problem was asked by Facebook.
 *
 * Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
 *
 * For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
 *
 * You can assume that the messages are decodable. For example, '001' is not allowed.
 */

int32_t decodingWays(std::string message) {
    // if the number begins with zero, then is not a valid message
    if(message[0] == '0')
        return 0;

    std::vector<int32_t> count{static_cast<int>(message.size() + 1), 0};
    // one is the total number of ways to decode an empty or a message of lenth one
    count[0] = 1;
    count[1] = 1;

    // go over all the numbers on the message, beging in the third place (second position in the array)
    for (size_t i = 2; i <= message.size(); ++i) {
        // if the last digit is not zero, add the last count to the current total
        if (message[i - 1] > '0')
            count[i] = count[i - 1];
        // if the second last digit is smaller than 2 and the last digit is smaller than 7, add
        // the last two digits count to the current total
        if (message[i - 2] == '1' || (message[i - 2] == '2' && message[i - 1] < '7'))
            count[i] += count[i - 2];
    }

    return count[message.size()];
}

TEST(PROBLEM_7, ValidExample) {
    ASSERT_TRUE(3 == decodingWays("111"));
}

TEST(PROBLEM_7, InvalidExample) {
    ASSERT_TRUE(0 == decodingWays("001"));
}

TEST(PROBLEM_7, AnotherValidExample) {
    ASSERT_TRUE(3 == decodingWays("1234"));
}
