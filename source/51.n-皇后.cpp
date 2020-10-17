/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
  public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nQueens(n, string(n, '.'));

        solve(res, nQueens, n, 0, 0, 0, 0);

        return res;
    }

    void solve(vector<vector<string>> &res, vector<string> &nQueens, int n,
               int row, int col_bit, int diag45_bit, int diag135_bit) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }

        int mask = col_bit | diag45_bit | diag135_bit;
        for (int i = 0, b = 1; i < n; i++, b <<= 1) {
            if (!(mask & b)) {
                nQueens[row][i] = 'Q';
                solve(res, nQueens, n, row + 1, col_bit | b,
                      (diag45_bit | b) << 1, (diag135_bit | b) >> 1);
                nQueens[row][i] = '.';
            }
        }
    }
};
// @lc code=end

