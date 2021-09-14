#
# @lc app=leetcode.cn id=743 lang=python3
#
# [743] 网络延迟时间
#

# @lc code=start
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        weight = collections.defaultdict(dict)
        for u, v, w in times:
            weight[u][v] = w
        heap = [(0, k)]
        dist = {}
        while heap:
            time, u = heapq.heappop(heap)
            if u not in dist:
                dist[u] = time
                for v in weight[u]:
                    heapq.heappush(heap, (dist[u]+weight[u][v], v))
        return max(dist.values()) if len(dist) == n else -1

# @lc code=end

