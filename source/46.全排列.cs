/*
 * @lc app=leetcode.cn id=46 lang=csharp
 *
 * [46] 全排列
 */

// @lc code=start
public class Solution {
    public IList<IList<int>> Permute(int[] nums) {
        var res = new List<IList<int>>();
        var path = new List<int>();
        var used = Enumerable.Repeat(false, nums.Length).ToArray();

        Permute(res, path, nums, used);

        return res;
    }

    private void Permute(IList<IList<int>> res, List<int> path, int[] nums, bool[] used) {
        if (path.Count == nums.Length) {
            res.Add(new List<int>(path));
            return;
        }

        for (int i = 0; i < nums.Length; i++) {
            if (used[i] == false) {
                used[i] = true;
                path.Add(nums[i]);
                Permute(res, path, nums, used);
                path.RemoveAt(path.Count - 1);
                used[i] = false;
            }
        }
    }
}
// @lc code=end

