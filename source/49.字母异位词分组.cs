/*
 * @lc app=leetcode.cn id=49 lang=csharp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
public class Solution {

    public IList<IList<string>> GroupAnagrams(string[] strs) {
        var result = new List<IList<string>>();
        if (strs.Length < 1) return result;

        var dict = new Dictionary<string, List<string>>();
        foreach(var s in strs) {
            var k = string.Concat(s.OrderBy(c => c));
            if (dict.ContainsKey(k))
                dict[k].Add(s);
            else
                dict[k] = new List<string>{s};
        }

        foreach(var kv in dict) {
            result.Add(kv.Value);
        }

        return result;
    }
}
// @lc code=end

