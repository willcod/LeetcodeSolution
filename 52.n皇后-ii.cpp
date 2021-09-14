/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
   public:
    int totalNQueens(int n) { return solve(n, 0, 0, 0, 0); }

    int solve(int n, int row, int col, int diag45, int diag135) {
        if (row == n) return 1;

        int available = ((1 << n) - 1) & (~(col | diag45 | diag135));
        int count = 0;
        while (available) {
            int pos = available & (-available);
            available = available & (available - 1);

            count += solve(n, row + 1, col | pos, (diag45 | pos) >> 1,
                           (diag135 | pos) << 1);
        }

        return count;
    }
};
// @lc code=end
