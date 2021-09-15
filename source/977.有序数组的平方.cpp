/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<int> sortedSquares(vector<int>& A) {
        int left = 0;
        int right = A.size() - 1;

        vector<int> res(A.size(), 0);

        for (int i = A.size() - 1; i >= 0; i--) {
            res[i] = pow(A[i], 2);
        }

        sort(res.begin(), res.end());

        return res;
    }
};
// @lc code=end
