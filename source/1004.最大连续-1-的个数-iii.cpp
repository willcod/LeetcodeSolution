/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int res = 0;
        int zeros = 0;
        int left = 0;

        for (int right = 0; right < A.size(); right++) {
            if (A[right] == 0) zeros++;
            while (zeros > K) {
                if (A[left++] == 0) --zeros;
            }
            res = max(res, right - left + 1);
        }

        return res;
    }
};
// @lc code=end

