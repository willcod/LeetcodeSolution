#
# @lc app=leetcode.cn id=567 lang=python3
#
# [567] 字符串的排列
#

# @lc code=start
from collections import defaultdict


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        hc1 = defaultdict(int)
        hc2 = defaultdict(int)
        for x in s1:
            hc1[x] += 1
        for x in s2[:len(s1)]:
            hc2[x] += 1

        left = 0
        right = len(s1)

        while right < len(s2):
            if hc2 == hc1:
                return True
            hc2[s2[left]] -= 1

            if hc2[s2[left]] < 1:
                hc2.pop(s2[left])

            hc2[s2[right]] = hc2.get(s2[right], 0) + 1
            left += 1
            right += 1

        return hc2 == hc1
# @lc code=end
