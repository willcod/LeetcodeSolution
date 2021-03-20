#
# @lc app=leetcode.cn id=978 lang=python
#
# [978] 最长湍流子数组
#

# @lc code=start
class Solution(object):
    def maxTurbulenceSize(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        N = len(arr)
        up = [1] * N
        down = [1] * N
        res = 1
        for i in range(1, N):
            if arr[i-1] < arr[i]:
                up[i] = down[i-1]+1
            elif arr[i-1] > arr[i]:
                down[i] = up[i-1] + 1
            res = max(up[i], down[i], res)
        return res
# @lc code=end
