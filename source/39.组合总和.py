#
# @lc app=leetcode.cn id=39 lang=python3
#
# [39] 组合总和
#

# @lc code=start
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()
        self.combinations(res, [], target, candidates, 0);
        return res;
    
    def combinations(self, res, sub, remain, candidates, index):
        if index >= len(candidates): return
        if remain == 0: 
            res.append(sub)
            return
        
        for i in range(index, len(candidates)):
            if remain < candidates[i]: break;
            # sub.append(candidates[i]);
            self.combinations(res, sub+[candidates[i]], remain-candidates[i], candidates, i);
            # sub.pop();


# @lc code=end

