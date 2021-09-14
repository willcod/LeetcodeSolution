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

        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            fill(board, i, 0);
            fill(board, i, cols - 1);
        }

        for (int i = 0; i < cols; i++) {
            fill(board, 0, i);
            fill(board, rows - 1, i);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void fill(vector<vector<char>>& board, int x, int y) {
        if (!isValid(board, x, y)) return;
        if (board[x][y] != 'O') return;

        board[x][y] = 'A';
        fill(board, x - 1, y);
        fill(board, x + 1, y);
        fill(board, x, y - 1);
        fill(board, x, y + 1);
    }

    bool isValid(vector<vector<char>>& board, int x, int y) {
        return x >= 0 && y >= 0 && x < board.size() && y < board[0].size();
    }
};
// @lc code=end
