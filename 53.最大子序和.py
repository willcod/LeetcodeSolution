#
# @lc app=leetcode.cn id=53 lang=python3
#
# [53] 最大子序和
#

# @lc code=start
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        Sum = nums[0]
        Max = nums[0]
        for i in range(1, len(nums)):
            if Sum + nums[i] < nums[i] :
                Sum = nums[i]
            else:
                Sum += nums[i]

            Max = max(Max, Sum)

        return Max 

# @lc code=end

