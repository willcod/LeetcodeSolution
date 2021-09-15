#
# @lc app=leetcode.cn id=16 lang=python3
#
# [16] 最接近的三数之和
#

# @lc code=start
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums = sorted(nums)

        res = nums[0]+nums[1]+nums[2]
        for i in range(len(nums)):
            left = i+1
            right = len(nums)-1

            while left < right:
                sumof3 = nums[i]+nums[left]+nums[right]
                if abs(sumof3-target) < abs(res-target):
                    res = sumof3

                if sumof3 == target:
                    return sumof3
                elif sumof3 < target:
                    left += 1
                else:
                    right -= 1

        return res

# @lc code=end
