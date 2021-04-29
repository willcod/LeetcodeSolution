#
# @lc app=leetcode.cn id=403 lang=python3
#
# [403] 青蛙过河
#

# @lc code=start
class Solution:
    def canCross(self, stones: List[int]) -> bool:
        if stones[1] - stones[0] > 1:
            return False

        stonesSet = set(stones)

        @functools.lru_cache(None)
        def dfs(i, step):
            if i >= stones[-1]:
                return True

            if i + step + 1 in stonesSet:
                if dfs(i+step+1, step+1):
                    return True

            if i + step in stonesSet:
                if dfs(i + step, step):
                    return True

            if step-1 > 0 and i + step - 1 in stonesSet:
                if dfs(i + step-1, step-1):
                    return True
            return False

        return dfs(stones[1], stones[1]-stones[0])
# @lc code=end
