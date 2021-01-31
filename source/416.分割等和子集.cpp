/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;

        int target = sum/2;
        sort(nums.begin(), nums.end());

        vector f(target+1, 0);
        f[0] = 1;

        for (int num : nums) {
            for (int i = target; i >= 0; i--) {
                if (i >= num) {
                    f[i] = f[i] || f[i-num];
                }
            }
        }
        return f[target];
    }
};
// @lc code=end

