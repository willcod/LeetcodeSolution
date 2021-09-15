/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 */

// @lc code=start
class Solution {
 public:
  bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
      dp[i][i] = nums[i];
    }

    for (int i = 1; i < n; i++) {
      for (int j = 0; i + j < n; j++) {
        dp[j][j + i] =
            max(nums[j + i] - dp[j][j + i - 1], nums[j] - dp[j + 1][j + i]);
      }
    }

    return dp[0][n - 1] >= 0;
  }
};
// @lc code=end
