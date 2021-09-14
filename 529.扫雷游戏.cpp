/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                     vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        updateBoard(board, click[0], click[1]);
        return board;
    }

    void updateBoard(vector<vector<char>>& board, int x, int y) {
        if (!isValid(board, x, y)) return;

        if (board[x][y] == 'E') {
            int count = 0;
            for (auto d : dirs) {
                int dx = x + d[0];
                int dy = y + d[1];
                if (!isValid(board, dx, dy)) continue;
                if (board[dx][dy] == 'M') count++;
            }

            if (count) {
                board[x][y] = count + '0';
            } else {
                board[x][y] = 'B';
                for (auto d : dirs) {
                    int dx = x + d[0];
                    int dy = y + d[1];
                    updateBoard(board, dx, dy);
                }
            }
        }
    }

    bool isValid(vector<vector<char>>& board, int x, int y) {
        return x >= 0 && y >= 0 && x < board.size() && y < board[0].size();
    }

   private:
    int dirs[8][2] = {{0, 1}, {1, 0},   {-1, 0}, {0, -1},
                      {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
};
// @lc code=end
