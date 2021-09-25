/*
 * @lc app=leetcode.cn id=73 lang=csharp
 *
 * [73] 矩阵置零
 */

// @lc code=start
public class Solution
{
  public void SetZeroes(int[][] matrix)
  {
    HashSet<int> rows = new HashSet<int>();
    HashSet<int> cols = new HashSet<int>();

    for (int i = 0; i < matrix.Length; i++) {
      for (int j = 0; j < matrix[0].Length; j++) {
        if (matrix[i][j] == 0) {
          rows.Add(i);
          cols.Add(j);
        }
      }
    }

    foreach (var row in rows) {
      for (int i = 0; i < matrix[0].Length; i++) {
        matrix[row][i] = 0;
      }
    }

    foreach (var col in cols) {
      for (int i = 0; i < matrix.Length; i++) {
        matrix[i][col] = 0;
      }
    }
  }
}
// @lc code=end

