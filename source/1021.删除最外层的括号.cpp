/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
 */

// @lc code=start
class Solution {
 public:
  string removeOuterParentheses(string S) {
    string result;
    int openCnt = 0;
    for (char c : S) {
      if (c == '(' && openCnt++ > 0) result += c;
      if (c == ')' && openCnt-- > 1) result += c;
    }
    return result;
  }
};
// @lc code=end
