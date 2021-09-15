#
# @lc app=leetcode.cn id=191 lang=python
#
# [191] 位1的个数
#

# @lc code=start
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        res = 0
        while n:
            res += n&1
            n >>= 1
        return res
# @lc code=end

