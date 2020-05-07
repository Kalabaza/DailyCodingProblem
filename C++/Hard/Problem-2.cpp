#include <gtest/gtest.h>
#include <numeric>
#include <vector>

/**
 * Asked by Uber
 *
 * Given an array of integers, return a new array such that each element at index i of the new array is the product
 * of all the numbers in the original array except the one at i.
 *
 * For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was
 * [3, 2, 1], the expected output would be [2, 3, 6].
 *
 * Follow-up: what if you can't use division?
 */
std::vector<int32_t> specialArrayProduct(std::vector<int32_t> numbers) {
    // Vector for the result values
    std::vector<int32_t> result;
    // Go over the array once to get the product of all the numbers and save that value
    int32_t product = std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies<int32_t>());
    // Then go over the array once more and insert in the new array, the result of dividing the previosly calculated
    // product by the current number in the array
    for(auto &number : numbers) {
        result.push_back(product / number);
    }
    // Return the new array of numbers as the result
    return result;
}

TEST(PROBLEM_2, ValidArraySum) {
    auto result = specialArrayProduct(std::vector<int32_t>{1, 2, 3, 4, 5});
    std::vector<int32_t> expected{120, 60, 40, 30, 24};
    ASSERT_TRUE(expected == result);
}

TEST(PROBLEM_2, InValidArraySum) {
    auto result = specialArrayProduct(std::vector<int32_t>{1, 2, 3, 4, 5});
    std::vector<int32_t> expected{1, 1, 1, 1, 1};
    ASSERT_TRUE(expected != result);
}

TEST(PROBLEM_2, SecondValidArraySum) {
    auto result = specialArrayProduct(std::vector<int32_t>{3, 2, 1});
    std::vector<int32_t> expected{2, 3, 6};
    ASSERT_TRUE(expected == result);
}

TEST(PROBLEM_2, ArrayOfOneElement) {
    auto result = specialArrayProduct(std::vector<int32_t>{2});
    std::vector<int32_t> expected{1};
    ASSERT_TRUE(expected == result);
}

TEST(PROBLEM_2, ArrayOfNegativeElements) {
    auto result = specialArrayProduct(std::vector<int32_t>{-3, -2, -1});
    std::vector<int32_t> expected{2, 3, 6};
    ASSERT_TRUE(expected == result);
}

TEST(PROBLEM_2, ArrayOfNegativeAndPositiveElements) {
    auto result = specialArrayProduct(std::vector<int32_t>{-3, 2, -1});
    std::vector<int32_t> expected{-2, 3, -6};
    ASSERT_TRUE(expected == result);
}

TEST(PROBLEM_2, SecondArrayOfNegativeAndPositiveElements) {
    auto result = specialArrayProduct(std::vector<int32_t>{3, -2, 1});
    std::vector<int32_t> expected{-2, 3, -6};
    ASSERT_TRUE(expected == result);
}

TEST(PROBLEM_2, ThirdArrayOfNegativeAndPositiveElements) {
    auto result = specialArrayProduct(std::vector<int32_t>{-3, -2, 1});
    std::vector<int32_t> expected{-2, -3, 6};
    ASSERT_TRUE(expected == result);
}

TEST(PROBLEM_2, FourthArrayOfNegativeAndPositiveElements) {
    auto result = specialArrayProduct(std::vector<int32_t>{3, -2, -1});
    std::vector<int32_t> expected{2, -3, -6};
    ASSERT_TRUE(expected == result);
}

TEST(PROBLEM_2, FifthArrayOfNegativeAndPositiveElements) {
    auto result = specialArrayProduct(std::vector<int32_t>{-3, 2, 1});
    std::vector<int32_t> expected{2, -3, -6};
    ASSERT_TRUE(expected == result);
}

TEST(PROBLEM_2, SixthArrayOfNegativeAndPositiveElements) {
    auto result = specialArrayProduct(std::vector<int32_t>{3, 2, -1});
    std::vector<int32_t> expected{-2, -3, 6};
    ASSERT_TRUE(expected == result);
}
