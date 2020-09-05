/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
// 二分法
class Solution {
 public:
  bool isPerfectSquare(int num) {
    if (num < 2) return true;

    int left = 2;
    int right = num / 2;

    while (left <= right) {
      long x = left + (right - left) / 2;
      long guess = x * x;
      if (guess == num)
        return true;

      else if (guess > num) {
        right = x - 1;
      } else {
        left = x + 1;
      }
    }
    return false;
  }
};
// @lc code=end

// 数学公式 n2 = 1 + 3 + 5 + ...
class Solution {
 public:
  bool isPerfectSquare(int num) {
    if (num < 2) return true;

    int x = 1;
    while (num > 0) {
      num -= x;
      x += 2;
    }

    return num == 0;
  }
};

// 牛顿迭代法
class Solution {
 public:
  bool isPerfectSquare(int num) {
    if (num < 2) return true;

    long x = num / 2;
    while (x * x > num) {
      x = (x + num / x) / 2;
    }

    return x * x == num;
  }
};