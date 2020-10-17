/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1);

        int fromBegin = 1;
        for (int i = 0; i < n; i++) {
            output[i] *= fromBegin;
            fromBegin *= nums[i];
        }

        int fromEnd = 1;
        for (int i = n - 1; i >= 0; i--) {
            output[i] *= fromEnd;
            fromEnd *= nums[i];
        }

        return output;
    }
};
// @lc code=end

