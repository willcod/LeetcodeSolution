/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();
        vector f(n, 1), c(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (f[j] + 1 > f[i]) {
                        f[i] = f[j] + 1;
                        c[i] = c[j];
                    } else if (f[j] + 1 == f[i]) {
                        c[i] += c[j];
                    }
                }
            }
        }

        int maxlen = *max_element(f.begin(), f.end());
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (f[i] == maxlen) {
                res += c[i];
            }
        }

        return res;
    }
};
// @lc code=end
