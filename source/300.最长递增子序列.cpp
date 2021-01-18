/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector f(n, 1);

        int maxlen = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    f[i] = max(f[i], f[j] + 1);
                    maxlen = max(maxlen, f[i]);
                }
            }
        }
        return maxlen;
    }
};
// @lc code=end
