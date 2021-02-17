#
# @lc app=leetcode.cn id=119 lang=python3
#
# [119] 杨辉三角 II
#

# 34/34 cases passed (36 ms)
# Your runtime beats 81.1 % of python3 submissions
# Your memory usage beats 33.27 % of python3 submissions (14.8 MB)
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        res = []
        for i in range(rowIndex+1):
            res.append(1)
            for j in range(len(res)-2, 0, -1):
                res[j] += res[j-1]
        return res
        
# @lc code=start
from typing import List


class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        res = []
        for i in range(rowIndex+1):
            res.append(1)
            for j in range(len(res)-2, 0, -1):
                res[j] += res[j-1]
        return res
# @lc code=end

if __name__ == '__main__':
    print(Solution().getRow(2))

