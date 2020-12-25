/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector f(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                f[i] = f[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                f[i] = max(f[i], f[i + 1] + 1);
            }
        }

        return accumulate(f.begin(), f.end(), 0);
    }
};
// @lc code=end
