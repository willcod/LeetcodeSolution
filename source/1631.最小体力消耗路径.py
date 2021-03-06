#
# @lc app=leetcode.cn id=1631 lang=python3
#
# [1631] 最小体力消耗路径
#

# @lc code=start
class Solution(object):
    def minimumEffortPath(self, heights):
        """
        :type heights: List[List[int]]
        :rtype: int
        """
        M, N = len(heights), len(heights[0])
        js = JointSet()
        edges = []
        for i in range(M):
            for j in range(N):
                pos = i * N + j
                if i < M - 1:
                    edges.append(
                        [abs(heights[i + 1][j] - heights[i][j]), pos, pos + N])
                if j < N - 1:
                    edges.append(
                        [abs(heights[i][j + 1] - heights[i][j]), pos, pos + 1])
        edges.sort()
        for edge in edges:
            js.union(edge[1], edge[2])
            if js.connected(0, M * N - 1):
                return edge[0]
        return 0


class JointSet:
    def __init__(self):
        self.par = [i for i in range(10001)]

    def find(self, x):
        if x != self.par[x]:
            self.par[x] = self.find(self.par[x])
        return self.par[x]

    def union(self, x, y):
        self.par[self.find(x)] = self.find(y)

    def connected(self, x, y):
        return self.find(x) == self.find(y)


# @lc code=end
