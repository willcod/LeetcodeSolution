/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
 public:
  int trailingZeroes(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
      int m = i;
      while (m) {
        if (m % 5 == 0) {
          count++;
          m /= 5;
        } else {
          break;
        }
      }
    }
    return count;
  }
};
// @lc code=end
