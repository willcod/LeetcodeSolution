#
# @lc app=leetcode.cn id=456 lang=python
#
# [456] 132模式
#

# @lc code=start
class Solution(object):
    def find132pattern(self, nums):
        N = len(nums)
        numsi = nums[0]
        for j in range(1, N):
            for k in range(N - 1, j, -1):
                if numsi < nums[k] and nums[k] < nums[j]:
                    return True
            numsi = min(numsi, nums[j])
        return False

# @lc code=end

