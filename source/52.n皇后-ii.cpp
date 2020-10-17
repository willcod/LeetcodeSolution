/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
  public:
    int totalNQueens(int n) { return solve(n, 0, 0, 0, 0); }

    int solve(int n, int row, int col, int diag1, int diag2) {
        if (row == n)
            return 1;

        int count = 0;
        int avaliable = ((1 << n) - 1) & (~(col | diag1 | diag2));

        while (avaliable) {
            int pos = avaliable & (-avaliable);
            avaliable = (avaliable - 1) & avaliable;

            count += solve(n, row + 1, col | pos, (diag1 | pos) << 1,
                           (diag2 | pos) >> 1);
        }

        return count;
    }
};
// @lc code=end
