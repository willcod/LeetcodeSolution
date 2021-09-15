#
# @lc app=leetcode.cn id=879 lang=python3
#
# [879] 盈利计划
#

# @lc code=start
class Solution:
    def profitableSchemes(self, n: int, minProfit: int, group: List[int], profit: List[int]) -> int:
        dp = [[0 for _ in range(minProfit + 1)] for _ in range(n + 1)]
        
        for people in range(n + 1):
            dp[people][0] = 1

        for cost, prof in zip(group, profit):
            for people in range(n, cost - 1, -1):
                for money in range(minProfit, -1, -1):
                    dp[people][money] += dp[people - cost][max(0, money - prof)]
                    dp[people][money] %= 10**9+7

        return dp[n][minProfit]
# @lc code=end

