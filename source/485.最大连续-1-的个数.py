#
# @lc app=leetcode.cn id=485 lang=python3
#
# [485] 最大连续1的个数
#

# @lc code=start
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        count = 0
        maxOne = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                count = 0
            else:
                count += 1
                
            maxOne = max(maxOne, count)
        
        return maxOne
# @lc code=end

