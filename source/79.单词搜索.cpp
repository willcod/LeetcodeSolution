/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include "cpp_includes.h"
// @lc code=start

/*
DFS + Backtrace
89/89 cases passed (412 ms)
Your runtime beats 14.77 % of cpp submissions
Your memory usage beats 8.9 % of cpp submissions (186.5 MB)
https://leetcode.com/problems/word-search/discuss/27675/My-19ms-accepted-C%2B%2B-code
*/
class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    if (word.empty()) return true;
    if (board.empty() || board[0].empty()) return false;

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (dfsSearch(board, word, i, j, 0)) return true;
      }
    }
    return false;
  }

  bool dfsSearch(vector<vector<char>>& board, string word, int x, int y,
                 int index) {
    if (!isValid(board, x, y) || word[index] != board[x][y]) return false;
    if (index == word.length() - 1) return true;

    char c = board[x][y];
    board[x][y] = '*';
    bool searchNext = dfsSearch(board, word, x + 1, y, index + 1) ||
                      dfsSearch(board, word, x - 1, y, index + 1) ||
                      dfsSearch(board, word, x, y + 1, index + 1) ||
                      dfsSearch(board, word, x, y - 1, index + 1);
    board[x][y] = c;
    return searchNext;
  }

  bool isValid(vector<vector<char>>& board, int x, int y) {
    return x >= 0 && y >= 0 && x < board.size() && y < board[0].size();
  }
};
// @lc code=end
