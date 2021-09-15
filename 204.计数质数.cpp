/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int countPrimes(int n) {
    vector<bool> prime(n, 1);
    int count = 0;
    for (int i = 2; i < n; i++) {
      if (prime[i]) {
        count++;
        if ((long)i * i < n) {
          for (int j = i * i; j < n; j += i) {
            prime[j] = 0;
          }
        }
      }
    }

    return count;
  }
};
// @lc code=end
