/*
 * @lc app=leetcode.cn id=482 lang=csharp
 *
 * [482] 密钥格式化
 */
using csharpnaming;
// @lc code=start
public class Solution
{
  public string LicenseKeyFormatting(string s, int k)
  {
    var sb = new StringBuilder();

    for (int i = s.Length - 1; i >= 0; i--)
    {
      if (Char.IsLetterOrDigit(s[i]))
      {
        if (sb.Length % (k + 1) == k) sb.Append('-');
        sb.Append(Char.ToUpper(s[i]));
      }
    }

    return new string(sb.ToString().Reverse().ToArray());
  }
}
// @lc code=end

