#
# @lc app=leetcode.cn id=73 lang=python3
#
# [73] 矩阵置零
#

# @lc code=start
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        flag_col = False
        row, col = len(matrix), len(matrix[0])
        for i in range(row):
            if matrix[i][0] == 0: flag_col = True
            for j in range(1, col):
                if matrix[i][j] == 0:
                    matrix[i][0] = matrix[0][j] = 0
        
        for i in range(row-1, -1, -1):
            for j in range(col-1, 0, -1):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
            
            if flag_col == True: matrix[i][0] = 0
# @lc code=end

