/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) return {};

    vector<string> result;
    getCombinations(result, digits, "", 0);
    return result;
  }

  void getCombinations(vector<string>& result, string digits, string s,
                       int index) {
    if (digits.size() == index) {
      result.push_back(s);
      return;
    }

    int digit = digits[index] - '0';
    string letters = letterMap[digit];
    for (int i = 0; i < letters.size(); i++) {
      getCombinations(result, digits, s + letters[i], index + 1);
    }
  }

 private:
  const string letterMap[10] = {"",    "",    "abc",  "def", "ghi",
                                "jkl", "mno", "pqrs", "tuv", "wxyz"};
};
// @lc code=end
