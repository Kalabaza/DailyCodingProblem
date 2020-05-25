#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

/**
 * This problem was asked by Stripe.
 *
 * Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the
 * lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.
 *
 * For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.
 *
 * You can modify the input array in-place.
 */
int32_t findMissingNumber(std::vector<int32_t> &numbers) {
    // Zero is used to signal an error on the input numbers
    int32_t result = 0;
    if(numbers.size() <= 1)
        return result;
    // Sort the numbers to look for the missing number
    std::sort(numbers.begin(), numbers.end());
    // Save the first number from the array.
    result = numbers[0];
    // Loop thru the rest of the numbers, to find the missing one in the sequence
    for(size_t index = 1; index < numbers.size(); ++index) {
        // If the current number is greater than the previous number by two, then it means that there is a missing number
        // or a jump in the sequence. Also the number 0 is not considered positive, so it does not count as missing.
        if(numbers[index] > result + 1 && 0 != result + 1) {
            ++result;
            break;
        }
        result = numbers[index];
    }
    // Check if the result was not found, meaning that a number after the last element in the array must be returned
    // as the result of the check
    if(result == numbers[numbers.size() - 1])
        ++result;
    return result;
}

TEST(PROBLEM_4, ValidExample) {
    std::vector<int32_t> numbers{3, 4, -1, 1};
    ASSERT_TRUE(2 == findMissingNumber(numbers));
}

TEST(PROBLEM_4, AnotherValidExample) {
    std::vector<int32_t> numbers{1, 2, 0};
    ASSERT_TRUE(3 == findMissingNumber(numbers));
}
