#include <gtest/gtest.h>
#include <set>
#include <vector>

/**
 * Given a list of numbers and a number k, return wheather any two numbers from the list add up to k.
 */
bool addUpTo(std::vector<int> numbers, int sum){
    // Check the size of the input data, it must have at least two numbers to do a sum of them
    if(numbers.size() <= 1)
        return false;
    // Set used to hold the difference of a number and the sum:
    // sum - num = diff
    std::set<int> diffs;
    diffs.insert(sum - numbers[0]);
    // The loop begins in the second number, since the difference with the sum and the first number
    // was already saved in the set, the loop will check if there is a number equal to this difference
    // in the remaining data
    for(uint index = 1; index < numbers.size(); ++index) {
        // If any previous difference is equal to the current number, it means that some previous number
        // plus the current number are equal to the sum
        if(diffs.count(numbers[index]) != 0) {
            return true;
        }
        // Otherwise insert the new difference to the set
        diffs.insert(sum - numbers[index]);
    }
    return false;
}

TEST(PROBLEM_1, ValidSumFound) {
    ASSERT_TRUE(addUpTo(std::vector<int>{10, 15, 3, 7}, 17));
}

TEST(PROBLEM_1, NoValidSumFound) {
    ASSERT_FALSE(addUpTo(std::vector<int>{10, 15, 3, 7}, 27));
}

TEST(PROBLEM_1, InvalidData) {
    ASSERT_FALSE(addUpTo(std::vector<int>{1}, 1));
}

TEST(PROBLEM_1, SmallData) {
    ASSERT_TRUE(addUpTo(std::vector<int>{1, 2}, 3));
}

TEST(PROBLEM_1, SmallDataIncorrectAnswer) {
    ASSERT_FALSE(addUpTo(std::vector<int>{1, 2}, 2));
}

TEST(PROBLEM_1, NegativeNumbers) {
    ASSERT_TRUE(addUpTo(std::vector<int>{-1, -2}, -3));
}

TEST(PROBLEM_1, NegativeAndPositiveNumbers) {
    ASSERT_TRUE(addUpTo(std::vector<int>{-1, 1}, 0));
}

TEST(PROBLEM_1, DuplicatedNumbers) {
    ASSERT_TRUE(addUpTo(std::vector<int>{5, 5}, 10));
}
