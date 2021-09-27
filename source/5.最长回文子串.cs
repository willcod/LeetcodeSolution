/*
 * @lc app=leetcode.cn id=5 lang=csharp
 *
 * [5] 最长回文子串
 */

// @lc code=start
public class Solution
{
  public string LongestPalindrome(string s)
  {
    if (s.Length < 2) return s;

    var start = 0;
    var maxlen = 1;
    var mid = 0;
    while (mid < s.Length)
    {
      int l = mid;
      int r = mid;

      while (r + 1 < s.Length && s[r] == s[r + 1]) r++;
      mid = r + 1;

      while (r + 1 < s.Length && l > 0 && s[r + 1] == s[l - 1])
      {
        r++;
        l--;
      }

      var len = r - l + 1;
      if (len > maxlen)
      {
        maxlen = len;
        start = l;
      }
    }

    return s.Substring(start, maxlen);
  }
}
// @lc code=end

