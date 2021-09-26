/*
 * @lc app=leetcode.cn id=3 lang=csharp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
public class Solution {
    public int LengthOfLongestSubstring(string s) {
        if (s.Length < 2) return s.Length;

        var left = 0;
        var right = 0;
        var maxlen = 0;

        var charSet = new HashSet<char>();
        
        while (right < s.Length) {
            if (charSet.Contains(s[right]) == false) {
                charSet.Add(s[right++]);
                maxlen = Math.Max(maxlen, right - left);
            } else {
                charSet.Remove(s[left++]);
            }
        }

        return maxlen;
    }
}
// @lc code=end

