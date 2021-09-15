#
# @lc app=leetcode.cn id=322 lang=python3
#
# [322] 零钱兑换
#

# @lc code=start
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        f = [amount+1]*(amount+1)
        f[0] = 0
        for i in range(0, amount+1):
            for coin in coins:
                if i >= coin:
                    f[i] = min(f[i], f[i-coin]+1)
        
        return f[amount] if f[amount] != amount+1 else -1
# @lc code=end

