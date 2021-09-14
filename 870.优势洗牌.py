#
# @lc app=leetcode.cn id=870 lang=python
#
# [870] 优势洗牌
#

# @lc code=start
class Solution(object):
    def advantageCount(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        sortedA = sorted(A)
        sortedB = sorted(B)

        assigned = {b: [] for b in B}
        remaining = []

        i = 0
        for a in sortedA:
            if a > sortedB[i]:
                assigned[sortedB[i]].append(a)
                i += 1
            else:
                remaining.append(a)
        
        return [assigned[b].pop() if assigned[b] else remaining.pop() for b in B]
        
# @lc code=end

