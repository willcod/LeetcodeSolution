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

        int target = sum / 2;
        int n = nums.size();

        vector f(n + 1, vector(target + 1, false));
        f[0][0] = true;

        for (int i = 1; i <= n; i++) {
            f[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                f[i][j] = f[i - 1][j];
                if (j >= nums[i - 1]) {
                    f[i][j] = f[i][j] || f[i - 1][j - nums[i - 1]];
                }
            }
        }
        return f[n][target];
    }
};
// @lc code=end
