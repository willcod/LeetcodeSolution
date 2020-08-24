/*
 * @lc app=leetcode.cn id=679 lang=cpp
 *
 * [679] 24 点游戏
 */

// @lc code=start
class Solution {
 public:
  bool judgePoint24(vector<int>& nums) {
    if (nums.size() != 4) return false;

    return judge24({nums.begin(), nums.end()});
  }

  bool judge24(vector<double> nums) {
    int n = nums.size();
    if (n == 1) return abs(nums[0] - 24) < 1e-10;

    sort(nums.begin(), nums.end());

    do {
      vector<double> temp(nums.begin(), nums.end() - 1);
      auto a = nums[n - 1];
      auto b = nums[n - 2];

      for (auto num : {a + b, a - b, a * b, a ? b / a : 0}) {
        temp.back() = num;
        if (judge24(temp)) return true;
      }
    } while (next_permutation(nums.begin(), nums.end()));

    return false;
  }
};
// @lc code=end
