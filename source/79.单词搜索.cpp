/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == word[0]) {
          if (find(board, word, i, j, 0) == true) {
            return true;
          }
        }
      }
    }

    return false;
  }

  bool find(vector<vector<char>>& board, string word, int x, int y, int index) {
    if (index == word.size()) return true;
    if (!IsValid(board, x, y) || board[x][y] != word[index]) return false;

    char c = board[x][y];
    board[x][y] = '*';
    bool found = find(board, word, x + 1, y, index + 1) ||
                 find(board, word, x - 1, y, index + 1) ||
                 find(board, word, x, y + 1, index + 1) ||
                 find(board, word, x, y - 1, index + 1);
    board[x][y] = c;

    return found;
  }

  bool IsValid(vector<vector<char>>& board, int x, int y) {
    return x >= 0 && y >= 0 && x < board.size() && y < board[0].size();
  }
};
// @lc code=end
