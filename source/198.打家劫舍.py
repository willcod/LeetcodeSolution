#
# @lc app=leetcode.cn id=198 lang=python3
#
# [198] 打家劫舍
#

# @lc code=start
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0: return 0
        if len(nums) == 1: return nums[0]
        
        n = len(nums)
        Cache = [0]*n
        Cache[0] = nums[0]
        Cache[1] = max(nums[0], nums[1])

        for i in range(2, n):
            Cache[i] = max(Cache[i-1], nums[i]+Cache[i-2])
        
        return Cache[-1];

# @lc code=end

