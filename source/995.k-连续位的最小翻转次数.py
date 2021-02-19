#
# @lc app=leetcode.cn id=995 lang=python3
#
# [995] K 连续位的最小翻转次数
#

# @lc code=start
class Solution:
    def minKBitFlips(self, A: List[int], K: int) -> int:
        res = cur = 0
        for i in range(len(A)):
            if i >= K and A[i-K] == 2:
                cur -= 1
            if (cur % 2) == A[i]:
                if i + K > len(A):
                    return -1
                A[i] = 2
                cur, res = cur + 1, res + 1
        return res


# @lc code=end
