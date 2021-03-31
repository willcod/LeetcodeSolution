#
# @lc app=leetcode.cn id=90 lang=python
#
# [90] 子集 II
#

# @lc code=start
class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        nums.sort()
        self.dfs(nums, 0, res, [])
        return res

    def dfs(self, nums, index, res, path):
        if path not in res:
            res.append(path)

        for i in range(index, len(nums)):
            if i > index and nums[i] == nums[i-1]:
                continue
            self.dfs(nums, i + 1, res, path + [nums[i]])
# @lc code=end
