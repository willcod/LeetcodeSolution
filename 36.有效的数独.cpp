/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][10] = {0, 0};
        bool col[9][10] = {0, 0};
        bool block[9][10] = {0, 0};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                auto val = board[i][j]-'0';

                if (row[i][val]) return false;
                if (col[j][val]) return false;
                if (block[j/3+i/3*3][val]) return false;

                row[i][val]= true;
                col[j][val] = true;
                block[j/3+i/3*3][val] = true;
            }
        }
        return true;
    }
};
// @lc code=end

