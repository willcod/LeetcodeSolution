/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n / 2; j++) 
                swap(A[i][j], A[i][m - j - 1]);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = !A[i][j];
            }
        }

        return A;
    }
};
// @lc code=end
