#
# @lc app=leetcode.cn id=209 lang=python3
#
# [209] 长度最小的子数组
#

# @lc code=start
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        if not nums:
            return 0

        ans = len(nums) + 1
        start, end = 0, 0
        total = 0
        while end < len(nums):
            total += nums[end]
            while total >= target:
                ans = min(ans, end - start+1)
                total -= nums[start]
                start += 1
            end += 1
        return 0 if ans == len(nums)+1 else ans

# @lc code=end
