/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;

    int m = matrix.size();
    int n = matrix[0].size();

    int left = 0;
    int right = n * m - 1;

    while (left <= right) {
      cout << left << ',' << right << endl;
      int mid = left + (right - left) / 2;
      int val = matrix[mid / n][mid % n];
      if (val == target) {
        return true;
      } else if (val < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return false;
  }
};
// @lc code=end

void main() {
  vector<vector<int>> matrix = {
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
  cout << (new Solution)->searchMatrix(matrix, 3);
}
