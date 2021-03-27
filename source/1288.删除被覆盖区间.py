#
# @lc app=leetcode.cn id=1288 lang=python
#
# [1288] 删除被覆盖区间
#

# @lc code=start
class Solution(object):
    def removeCoveredIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        intervals.sort(key = lambda x: (x[0], -x[1]))
        count = 0

        prev_end = 0
        for _, end in intervals:
            if end > prev_end:
                count += 1
                prev_end = end
        return count
# @lc code=end

