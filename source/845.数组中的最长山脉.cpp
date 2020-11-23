/*
 * @lc app=leetcode.cn id=845 lang=cpp
 *
 * [845] 数组中的最长山脉
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        if (n < 3) return 0;

        vector f(n, 1);
        vector b(n, 1);

        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1]) f[i] = f[i - 1] + 1;
        }

        for (int i = n - 2; i >= 0; i--) {
            if (A[i] > A[i + 1]) b[i] = b[i + 1] + 1;
        }

        int maxlen = 0;
        for (int i = 0; i < n; i++) {
            if (f[i] > 1 && b[i] > 1) {
                maxlen = max(maxlen, f[i] + b[i] - 1);
            }
        }

        return maxlen;
    }
};
// @lc code=end
