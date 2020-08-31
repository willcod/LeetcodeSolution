/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.length();
    }
};
// @lc code=end
class Solution {
 public:
  bool repeatedSubstringPattern(string str) {
    int n = str.length();
    for (int i = 1; i <= n / 2; i++) {
      if (n % i == 0 && str.substr(i) == str.substr(0, n - i)) return true;
    }

    return false;
  }
};
