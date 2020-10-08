/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            flood(board, i, 0);
            flood(board, i, n - 1);
        }

        for (int i = 0; i < n; i++) {
            flood(board, 0, i);
            flood(board, m - 1, i);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void flood(vector<vector<char>>& board, int x, int y) {
        if (!isValid(board, x, y)) return;

        if (board[x][y] == 'O') {
            board[x][y] = 'A';
            flood(board, x - 1, y);
            flood(board, x + 1, y);
            flood(board, x, y - 1);
            flood(board, x, y + 1);
        }
    }

    bool isValid(vector<vector<char>>& board, int x, int y) {
        return x >= 0 && y >= 0 && x < board.size() && y < board[0].size();
    }
};
// @lc code=end
