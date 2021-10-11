/*
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 private:
  string within20[20] = {"Zero",    "One",       "Two",      "Three",
                       "Four",    "Five",      "Six",      "Seven",
                       "Eight",   "Nine",      "Ten",      "Eleven",
                       "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
                       "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
  string tens[10] = {"Zero",  "Ten",   "Twenty",  "Thirty", "Forty",
                     "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

  const int Billion = 1000000000;
  const int Million = 1000000;
  const int Thousand = 1000;
  const int Hundred = 100;

 public:
  string numberToWords(int num) {
    if (num == 0)
      return "Zero";
    else
      return int2string(num).substr(1);
  }

  string int2string(int n) {
    if (n >= Billion) {
      return int2string(n / Billion) + " Billion" + int2string(n % Billion);
    } else if (n >= Million) {
      return int2string(n / Million) + " Million" + int2string(n % Million);
    } else if (n >= Thousand) {
      return int2string(n / Thousand) + " Thousand" + int2string(n % Thousand);
    } else if (n >= Hundred) {
      return int2string(n / Hundred) + " Hundred" + int2string(n % Hundred);
    } else if (n >= 20) {
      return " " + tens[n / 10] + int2string(n % 10);
    } else if (n >= 1) {
      return " " + within20[n];
    } else {
      return "";
    }
  }
};
// @lc code=end
