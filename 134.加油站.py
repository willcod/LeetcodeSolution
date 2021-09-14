#
# @lc app=leetcode.cn id=134 lang=python3
#
# [134] 加油站
#

# @lc code=start
class Solution:
    def canCompleteCircuit(self, gas, cost):
        if sum(gas) < sum(cost):
            return -1
        
        n, start, left = len(gas), 0, 0
        for i in range(n):
            left += gas[i] - cost[i]
            if left < 0:
                start = i + 1
                left = 0
        return start
        
# @lc code=end

