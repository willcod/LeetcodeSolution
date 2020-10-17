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
        int n = A.size();

        vector<int> res(n, 0);

        int left = 0;
        int right = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (abs(A[right] > abs(A[left]))) {
                res[i] = pow(A[right--], 2);
            } else {
                res[i] = pow(A[left++], 2);
            }
        }

        return res;
    }
};
// @lc code=end
