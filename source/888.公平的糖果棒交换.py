#
# @lc app=leetcode.cn id=888 lang=python3
#
# [888] 公平的糖果交换
#

# @lc code=start
class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        diff = sum(B) - sum(A)
        setA = set(A)

        for b in B:
            if b - diff // 2 in setA:
                return [b-diff//2, b]

# @lc code=end
