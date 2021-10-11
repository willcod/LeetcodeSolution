#
# @lc app=leetcode.cn id=441 lang=python3
#
# [441] 排列硬币
#

# @lc code=start
class Solution:
    def arrangeCoins(self, n: int) -> int:
        r = 0
        while n > 0:
            if n - r - 1 < 0:
                break;
            r += 1
            n -= r
        
        return r
# @lc code=end

