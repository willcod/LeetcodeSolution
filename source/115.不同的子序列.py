#
# @lc app=leetcode.cn id=115 lang=python3
#
# [115] 不同的子序列
#

# @lc code=start
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n, m = len(s), len(t)
        dp = [[0]*(n+1) for _ in range(m+1)]
        for j in range(n+1):
            dp[0][j] = 1
        for i in range(1, m+1):
            for j in range(1, n+1):
                if t[i-1] == s[j-1]:
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1]
                else:
                    dp[i][j] = dp[i][j-1]

        return dp[-1][-1]

# @lc code=end
if __name__ == '__main__':
    S = Solution()
    S.numDistinct("rabbbit", "rabbit")
