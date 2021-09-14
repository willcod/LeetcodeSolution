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
        generateParent(res, path, n, 0);
        return res;
    }

    void generateParent(vector<string>& res, string path, int open, int close) {
        if (!open && !close) {
            res.push_back(path);
            return;
        }

        if (open) generateParent(res, path + '(', open - 1, close + 1);
        if (close) generateParent(res, path + ')', open, close - 1);
    }
};
// @lc code=end
