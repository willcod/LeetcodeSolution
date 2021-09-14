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
                    if (find_word(board, i, j, word, 0)) return true;
                }
            }
        }

        return false;
    }

    bool find_word(vector<vector<char>>& board, int x, int y, string word,
                   int index) {
        if (!isValid(board, x, y) || word[index] != board[x][y]) return false;
        if (index == word.size() - 1) return true;

        char c = board[x][y];
        board[x][y] = '*';
        bool is_found = find_word(board, x - 1, y, word, index + 1) ||
                        find_word(board, x + 1, y, word, index + 1) ||
                        find_word(board, x, y - 1, word, index + 1) ||
                        find_word(board, x, y + 1, word, index + 1);
        board[x][y] = c;
        return is_found;
    }

    bool isValid(vector<vector<char>>& board, int x, int y) {
        return x >= 0 && y >= 0 && x < board.size() && y < board[0].size();
    }
};
// @lc code=end
