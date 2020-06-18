#include <gtest/gtest.h>
#include <utility>

/**
 * This problem was asked by Jane Street.
 *
 * cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair.
 *
 * For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.
 * Given this implementation of cons:
 *
 * def cons(a, b):
 *     def pair(f):
 *         return f(a, b)
 *     return pair
 * Implement car and cdr.
 */

int32_t car(std::pair<int32_t, int32_t> data) {
    return data.first;
}

int32_t cdr(std::pair<int32_t, int32_t> data) {
    return data.second;
}

TEST(PROBLEM_5, ValidExample) {
    auto data = std::make_pair(3, 4);
    ASSERT_TRUE(3 == car(data));
    ASSERT_TRUE(4 == cdr(data));
}
