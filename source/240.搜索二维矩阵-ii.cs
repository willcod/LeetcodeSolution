/*
 * @lc app=leetcode.cn id=240 lang=csharp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
public class Solution {
    public bool SearchMatrix(int[,] matrix, int target) {
        int m = matrix.GetLength(0);
        int n = matrix.GetLength(1);

        int row = m - 1;
        int col = 0;

        while (row >= 0 && col < n) {
            if (matrix[row, col] == target) return true;

            if (matrix[row, col] > target) {
                row--;
            } else {
                col++;
            }
        }
        return false;
    }
}
// @lc code=end

