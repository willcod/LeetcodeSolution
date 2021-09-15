#
# @lc app=leetcode.cn id=207 lang=python3
#
# [207] 课程表
#

# @lc code=start
class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        edges = collections.defaultdict(list)
        visited = [0] * numCourses
        result = []
        valid = True

        for info in prerequisites:
            edges[info[1]].append(info[0])

        def dfs(u: int):
            nonlocal valid
            visited[u] = 1
            for v in edges[u]:
                if visited[v] == 0:
                    dfs(v)
                    if not valid:
                        return
                elif visited[v] == 1:
                    valid = False
                    return
            visited[u] = 2
            result.append(u)

        for i in range(numCourses):
            if valid and not visited[i]:
                dfs(i)
        
        return valid
# @lc code=end

