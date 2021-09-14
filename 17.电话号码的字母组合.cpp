/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};

    vector<string> result;
    getCombination(result, digits, "", 0);
    return result;
  }

 private:
  void getCombination(vector<string>& result, string digits, string s,
                      int index) {
    if (index == digits.length()) {
      result.push_back(s);
      return;
    }

    string letters = keyboard[digits[index] - '0'];
    for (auto l : letters) {
      getCombination(result, digits, s + l, index + 1);
    }
  }

 private:
  string keyboard[10] = {"",    "",    "abc",  "def", "ghi",
                         "jkl", "mno", "pqrs", "tuv", "wxyz"};
};
// @lc code=end
