#
# @lc app=leetcode.cn id=119 lang=python3
#
# [119] 杨辉三角 II
#

# @lc code=start
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        row = []
        for i in range(rowIndex+1):
            row.append(1)
            for j in range(i-1, 0, -1):
                row[j] += row[j-1]
        
        return row
# @lc code=end

