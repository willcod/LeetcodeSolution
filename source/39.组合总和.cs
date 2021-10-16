/*
 * @lc app=leetcode.cn id=39 lang=csharp
 *
 * [39] 组合总和
 */
using csharpnaming;
// @lc code=start
public class Solution {
    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        var result = new List<IList<int>>();
        var sub = new List<int>();

        Array.Sort(candidates);
        Combination(result, sub, target, candidates, 0);
        return result;
    }

    void Combination(List<IList<int>> result, IList<int> sub, int remain, int[] candidates, int index) {
        if (index >= candidates.Length) return;
        if (remain == 0) {
            result.Add(new List<int>(sub));
            return;
        }

        for (int i = index; i < candidates.Length; i++) {
            if (remain < candidates[i]) break;
            sub.Add(candidates[i]);
            Combination(result, sub, remain-candidates[i], candidates, i);
            sub.RemoveAt(sub.Count-1);
        }
    }
}
// @lc code=end

