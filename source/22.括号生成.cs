/*
 * @lc app=leetcode.cn id=22 lang=csharp
 *
 * [22] 括号生成
 */

// @lc code=start
public class Solution
{
  public IList<string> GenerateParenthesis(int n)
  {
    var result = new List<string>();
    string str = "";
    GenerateParenthesis(result, str, n, 0);
    return result;
  }

  private void GenerateParenthesis(IList<string> result, string str, int left, int right)
  {
    if (left == 0 && right == 0)
    {
      result.Add(str);
      return;
    }
    if (left != 0) GenerateParenthesis(result, str + '(', left - 1, right + 1);
    if (right != 0) GenerateParenthesis(result, str + ')', left, right - 1);
  }
}
// @lc code=end

