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
        int maxlen = 0;

        for (int i = 1; i < A.size();) {
            int inc = 0, dec = 0;

            while (i < A.size() && A[i - 1] < A[i]) i++, inc++;
            while (i < A.size() && A[i - 1] > A[i]) i++, dec++;

            if (inc > 0 && dec > 0) {
                maxlen = max(maxlen, inc + dec + 1);
            }

            while (i < A.size() && A[i - 1] == A[i]) i++;
        }

        return maxlen;
    }
};
// @lc code=end
