/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int squareSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += pow(n % 10, 2);
            n /= 10;
        }

        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = squareSum(n);
        while (slow != fast) {
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
        }

        return slow == 1;
    }
};
// @lc code=end
