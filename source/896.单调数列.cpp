/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        bool inc = true;
        bool dec = true;

        for (int i = 0; i < n - 1; i++) {
            if (A[i] > A[i + 1]) {
                inc = false;
            }

            if (A[i] < A[i + 1]) {
                dec = false;
            }
        }
        return inc || dec;
    }
};
// @lc code=end
