#
# @lc app=leetcode.cn id=767 lang=python
#
# [767] 重构字符串
#

# @lc code=start
class Solution(object):
    def reorganizeString(self, S):
        """
        :type S: str
        :rtype: str
        """
        res = ""
        counter = collections.Counter(S)
        if max(counter.values()) > (len(S)+1) // 2:
            return res
        
        pq = []
        for key, val in counter.items():
            heapq.heappush(pq, (-val, key))
        
        prev = (0, None)

        while pq:
            v, k = heapq.heappop(pq)
            res += k
            if prev[0] < 0:
                heapq.heappush(pq, prev)
            prev = (v+1, k)
        
        return res
# @lc code=end

