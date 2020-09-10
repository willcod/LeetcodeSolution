/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
/*

*/
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int max = INT_MIN;
    int n = nums.size();
    int dp = nums[0];
    max = dp;
    for (int i = 1; i < nums.size(); i++) {
      dp = std::max(dp + nums[i], nums[i]);
      max = std::max(dp, max);
    }

    return max;
  }
};
// @lc code=end
// 暴力解法 TLE
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int max = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
      int sum = 0;
      for (int j = i; j < nums.size(); j++) {
        sum += nums[j];
        max = std::max(sum, max);
      }
    }
    return max;
  }
};

/*
DP with O(n) space
202/202 cases passed (12 ms)
Your runtime beats 16.12 % of cpp submissions
Your memory usage beats 5.01 % of cpp submissions (13.5 MB)
*/
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int max = INT_MIN;
    int n = nums.size();
    vector<int> dp(n, 0);

    dp[0] = nums[0];
    max = dp[0];
    for (int i = 1; i < nums.size(); i++) {
      dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
      max = std::max(dp[i], max);
    }

    return max;
  }
};

/*
DP with O(1) space
202/202 cases passed (16 ms)
Your runtime beats 8.3 % of cpp submissions
Your memory usage beats 5.01 % of cpp submissions (13.3 MB)
*/
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int max = INT_MIN;
    int n = nums.size();
    int dp = nums[0];
    max = dp;
    for (int i = 1; i < nums.size(); i++) {
      dp = std::max(dp + nums[i], nums[i]);
      max = std::max(dp, max);
    }

    return max;
  }
};