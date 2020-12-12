/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int wiggleMaxLength(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) return n;

        int up = 1, down = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1])
                down = up + 1;
            else if (nums[i] > nums[i - 1])
                up = down + 1;
        }
        return max(up, down);
    }
};
// @lc code=end
