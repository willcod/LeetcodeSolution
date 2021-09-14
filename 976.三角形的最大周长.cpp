/*
 * @lc app=leetcode.cn id=976 lang=cpp
 *
 * [976] 三角形的最大周长
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int largestPerimeter(vector<int> &A) {
        sort(A.rbegin(), A.rend());
        for (int i = 0; i < A.size() - 2; i++) {
            if (A[i] < A[i + 1] + A[i + 2]) {
                return A[i] + A[i + 1] + A[i + 2];
            }
        }
        return 0;
    }
};
// @lc code=end
