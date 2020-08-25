/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    addParen(res, "", n, 0);
    return res;
  }

  void addParen(vector<string>& res, string str, int left, int right) {
    if (left == 0 && right == 0) {
      res.push_back(str);
      return;
    }

    if (right > 0) {
      addParen(res, str + ")", left, right - 1);
    }
    if (left > 0) {
      addParen(res, str + "(", left - 1, right + 1);
    }
  }
};
// @lc code=end
