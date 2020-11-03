/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        generate(res, path, n, 0);
        return res;
    }

    void generate(vector<string>& res, string path, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(path);
            return;
        }

        if (left > 0) {
            generate(res, path + '(', left - 1, right + 1);
        }

        if (right > 0) {
            generate(res, path + ')', left, right - 1);
        }
    }
};
// @lc code=end
