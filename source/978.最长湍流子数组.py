#
# @lc app=leetcode.cn id=978 lang=python3
#
# [978] 最长湍流子数组
#

# @lc code=start
class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        N = len(arr)
        up = [1] * N
        down = [1] * N
        Len = 1
        for i in range(1, N):
            if arr[i-1] < arr[i]:
                up[i] = down[i-1] + 1
            elif arr[i-1] > arr[i]:
                down[i] = up[i-1] + 1
            Len = max(Len, up[i], down[i])
        return Len
# @lc code=end
