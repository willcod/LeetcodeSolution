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
        if (A.size() < 3) return 0;

        int maxlen = 0;
        for (int i = 1; i < A.size() - 1; i++) {
            if (A[i] > A[i + 1] && A[i] > A[i - 1]) {
                int left = i - 1;
                int right = i + 1;

                while (left > 0 && A[left] > A[left - 1]) left--;
                while (right < A.size() - 1 && A[right] > A[right + 1]) right++;

                maxlen = max(maxlen, right - left + 1);
            }
        }
        return maxlen;
    }
};
// @lc code=end
