#include <gtest/gtest.h>
#include <set>
#include <vector>

/**
 * Asked by Google
 *
 * Given a list of numbers and a number k, return wheather any two numbers from the list add up to k.
 *
 * For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
 *
 * Bonus: Can you do this in one pass?
 */
bool addUpTo(const std::vector<int32_t> &numbers, int32_t sum){
    // Check the size of the list of numbers, it must have at least two numbers to do a sum of them
    if(numbers.size() <= 1)
        return false;
    // A set is used to hold the difference between a number and the expected sum k:
    // diff = sum - num
    std::set<int32_t> diffs;
    // First, insert the difference between the sum and the first number in the list
    diffs.insert(sum - numbers[0]);
    // The loop begins in the second number, the loop will check if there is a number equal to this
    // difference in the remaining list of numbers
    for(uint index = 1; index < numbers.size(); ++index) {
        // If any previous difference is equal to the current number, it means that some previous number
        // plus the current one are equal to the target sum
        if(diffs.count(numbers[index]) != 0) {
            return true;
        }
        // Otherwise insert the new difference to the set and take a new number
        diffs.insert(sum - numbers[index]);
    }
    // If this point is reached, it means that no two numbers were found that add up to the target sum
    return false;
}

TEST(PROBLEM_1, ValidSumFound) {
    ASSERT_TRUE(addUpTo(std::vector<int32_t>{10, 15, 3, 7}, 17));
}

TEST(PROBLEM_1, NoValidSumFound) {
    ASSERT_FALSE(addUpTo(std::vector<int32_t>{10, 15, 3, 7}, 27));
}

TEST(PROBLEM_1, InvalidList) {
    ASSERT_FALSE(addUpTo(std::vector<int32_t>{1}, 1));
}

TEST(PROBLEM_1, SmallList) {
    ASSERT_TRUE(addUpTo(std::vector<int32_t>{1, 2}, 3));
}

TEST(PROBLEM_1, SmallListIncorrectAnswer) {
    ASSERT_FALSE(addUpTo(std::vector<int32_t>{1, 2}, 2));
}

TEST(PROBLEM_1, NegativeNumbers) {
    ASSERT_TRUE(addUpTo(std::vector<int32_t>{-1, -2}, -3));
}

TEST(PROBLEM_1, NegativeAndPositiveNumbers) {
    ASSERT_TRUE(addUpTo(std::vector<int32_t>{-1, 1}, 0));
}

TEST(PROBLEM_1, DuplicatedNumbers) {
    ASSERT_TRUE(addUpTo(std::vector<int32_t>{5, 5}, 10));
}
