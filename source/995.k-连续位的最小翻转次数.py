#
# @lc app=leetcode.cn id=995 lang=python
#
# [995] K 连续位的最小翻转次数
#

# @lc code=start
class Solution(object):
    def minKBitFlips(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        res = cur = 0
        for i in range(len(A)):
            if i >= K and A[i-K] == 2:
                cur -= 1
            if (cur % 2) == A[i]:
                if i + K > len(A):
                    return -1
                A[i] = 2
                cur, res = cur+1, res+1
        return res
        
# @lc code=end

