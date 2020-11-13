/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第K小的元素
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        return matrix[k/n][k%n];
    }
};
// @lc code=end

