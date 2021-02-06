#
# @lc app=leetcode.cn id=279 lang=python3
#
# [279] 完全平方数
#

# @lc code=start
class Solution:
    def numSquares(self, n: int) -> int:
        f = [0]*(n+1)
        for i in range(1, n+1):
            f[i] = i
            for j in range(1, int(i**(0.5))+1):
                f[i] = min(f[i], f[i-j*j]+1)

        return f[n]
# @lc code=end
