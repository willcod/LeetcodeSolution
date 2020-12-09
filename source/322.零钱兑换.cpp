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
        int total = INT_MAX;
        coinChange(coins, amount, 0, 0, total);
        return total == INT_MAX ? -1 : total;
    }

    void coinChange(vector<int>& coins, int amount, int index, int count, int& total) {
        if (amount == 0) {
            total = min(total, count);
            return;
        }

        if (index >= coins.size()) return;

        for (int k = amount/coins[index]; k >= 0 && count+k < total; k-- ) {
            coinChange(coins, amount - k*coins[index], index+1, count+k, total);
        }
    }
};
// @lc code=end

