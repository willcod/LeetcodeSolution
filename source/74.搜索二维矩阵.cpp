/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;

    int rown = matrix.size();
    int coln = matrix[0].size();
    int start = 0;
    int end = rown * coln - 1;

    while (start <= end) {
      int mid = start + (end - start) / 2;
      int e = matrix[mid / coln][mid % coln];

      if (e > target) {
        end = mid - 1;
      } else if (e < target) {
        start = mid + 1;
      } else {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
