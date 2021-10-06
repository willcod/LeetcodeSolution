/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 private:
  const string keyboard[10] = {"",    "!@#", "abc",  "def", "ghi",
                               "jkl", "mno", "pqrs", "tuv", "wxyz"};

 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> res;

    string str;
    letterCombinations(res, str, digits, 0);

    return res;
  }

  void letterCombinations(vector<string>& res, string str, string digits,
                          int index) {
    if (index >= digits.size()) {
      res.push_back(str);
      return;
    }

    string chars = keyboard[digits[index] - '0'];
    for (auto c : chars) {
      letterCombinations(res, str + c, digits, index + 1);
    }
  }
};
// @lc code=end
