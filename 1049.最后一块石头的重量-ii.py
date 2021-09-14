#
# @lc app=leetcode.cn id=1049 lang=python
#
# [1049] 最后一块石头的重量 II
#

# @lc code=start
class Solution(object):
    def lastStoneWeightII(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        target = sum(stones)/2.0
        candidates = {0}

        for x in stones:
            addition = set()
            for y in candidates:
                s = x + y
                if s == target:
                    return 0
                elif x+y < target:
                    addition.add(s)
            candidates = candidates.union(addition)
        return int(2*(target-max(candidates)))
# @lc code=end

