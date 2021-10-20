/*
 * @lc app=leetcode.cn id=453 lang=csharp
 *
 * [453] 最小操作次数使数组元素相等
 */

// @lc code=start
public class Solution
{
  public int MinMoves(int[] nums)
  {
    var count = 0;
    var min = nums.Min(e => e);

    foreach (var n in nums)
    {
      count += n - min;
    }
    return count;
  }
}
// @lc code=end

