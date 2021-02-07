#
# @lc app=leetcode.cn id=1423 lang=python3
#
# [1423] 可获得的最大点数
#

# @lc code=start
class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        total = sum(cardPoints)
        n = len(cardPoints)
        window = n - k

        windowSum = 0
        minSum = float("inf")
        for i in range(n):
            windowSum += cardPoints[i]
            if i >= window:
                windowSum -= cardPoints[i-window]
            if i >= window - 1:
                minSum = min(minSum, windowSum)

        return total - minSum

# @lc code=end
