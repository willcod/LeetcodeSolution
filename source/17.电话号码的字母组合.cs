/*
 * @lc app=leetcode.cn id=17 lang=csharp
 *
 * [17] 电话号码的字母组合
 */
using csharpnaming;
// @lc code=start
public class Solution
{
  private List<string> keyboard = new List<string>() {
      "", "", "abc", "def", "ghi", "jkl",
      "mno", "pqrs", "tuv", "wxyz" };
  public IList<string> LetterCombinations(string digits)
  {
      if (digits=="") return new List<string>();
      var res = new List<string>();
      string str = "";

      LetterCombinations(res, str, digits, 0);
      return res;
  }

  private void LetterCombinations(List<string> res, string str, string digits, int index) {
      if (index == digits.Length) {
          res.Add(str);
          return;
      }

      string chars = keyboard[digits[index] - '0'];
      foreach(var c in chars) {
          LetterCombinations(res, str+c, digits, index+1);
      }
  }
}
// @lc code=end

