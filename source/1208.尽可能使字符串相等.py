#
# @lc app=leetcode.cn id=1208 lang=python3
#
# [1208] 尽可能使字符串相等
#

# @lc code=start
class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        length = len(s)
        costs = [0] * length
        for i in range(length):
            costs[i] = abs(ord(s[i]) - ord(t[i]))
        left, right = 0, 0
        res = 0
        sums = 0
        while right < length:
            sums += costs[right]
            while sums > maxCost:
                sums -= costs[left]
                left += 1
            res = max(res, right - left + 1)
            right += 1
        return res

# @lc code=end

