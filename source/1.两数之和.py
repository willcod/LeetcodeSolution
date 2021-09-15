#
# @lc app=leetcode.cn id=1 lang=python3
#
# [1] 两数之和
#


# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict = {}
        for i, num in enumerate(nums):
            if target - num in dict:
                return [dict[target - num], i]
            dict[nums[i]] = i
        return []


# @lc code=end
