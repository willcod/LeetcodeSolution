/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */
#include "./cpp_includes.h"
// @lc code=start
class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";

    string result = "";
    if (numerator < 0 ^ denominator < 0) result += "-";

    int64_t n = abs(numerator);
    int64_t d = abs(denominator);

    result += to_string(n / d);
    if (n % d == 0) return result;

    result += '.';

    unordered_map<int64_t, int> posMap;

    int64_t remain = n % d;
    while (remain != 0) {
      if (posMap.count(remain) > 0) {
        result.insert(posMap[remain], 1, '(');
        result += ')';
        break;
      }
      posMap[remain] = result.length();
      remain *= 10;

      result += to_string(remain / d);
      remain %= d;
    }
    return result;
  }
};
// @lc code=end
