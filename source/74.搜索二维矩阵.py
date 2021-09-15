#
# @lc app=leetcode.cn id=74 lang=python
#
# [74] 搜索二维矩阵
#

# @lc code=start
class Solution(object):
    # def searchMatrix(self, matrix, target):
    #     """
    #     :type matrix: List[List[int]]
    #     :type target: int
    #     :rtype: bool
    #     """
    #     M, N = len(matrix), len(matrix[0])
    #     left, right = 0, M * N - 1
    #     while left <= right:
    #         mid = left + (right - left) // 2
    #         cur = matrix[mid // N][mid % N]
    #         if cur == target:
    #             return True
    #         elif cur < target:
    #             left = mid + 1
    #         else:
    #             right = mid - 1
    #     return False


    def searchMatrix(self, matrix, target):
        M, N = len(matrix), len(matrix[0])
        for i in range(M):
            for j in range(N):
                if matrix[i][j] == target:
                    return True
        return False

# @lc code=end

