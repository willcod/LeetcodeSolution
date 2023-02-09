/*
 * @lc app=leetcode.cn id=1233 lang=csharp
 *
 * [1233] 删除子文件夹
 */

// @lc code=start
public class Solution {
    public IList<string> RemoveSubfolders(string[] folder) {
        Array.Sort(folder);
        var ans = new List<string>();
        ans.Add(folder[0]);

        for(int i = 1; i < folder.Length; i++){
            int pre = ans[ans.Count - 1].Length;
            if (!(pre < folder[i].Length && ans[ans.Count-1].Equals(folder[i].Substring(0, pre))
            && folder[i][pre] == '/')){
                ans.Add(folder[i]);
            }
        }

        return ans;
    }
}
// @lc code=end

