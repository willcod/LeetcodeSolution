/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    sort(coins.rbegin(), coins.rend());
    int res = INT_MAX;
    coinChange(coins, amount, 0, 0, res);
    return res == INT_MAX ? -1 : res;
  }

  void coinChange(vector<int>& coins, int amount, int index, int count,
                  int& res) {
    if (amount == 0) {
      res = min(count, res);
      return;
    }

    if (index == coins.size()) return;

    for (int c = amount / coins[index]; c >= 0 && c + count < res; c--) {
      coinChange(coins, amount - c * coins[index], index + 1, c + count, res);
    }
  }
};
// @lc code=end
