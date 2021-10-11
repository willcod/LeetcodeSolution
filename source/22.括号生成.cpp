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
    string str;
    generateParenthesis(res, str, n, 0);
    return res;
  }

  void generateParenthesis(vector<string>& res, string str, int l, int r) {
    if (!l && !r) {
      res.push_back(str);
      return;
    }

    if (l) generateParenthesis(res, str + '(', l - 1, r + 1);
    if (r) generateParenthesis(res, str + ')', l, r - 1);
  }
};
// @lc code=end
