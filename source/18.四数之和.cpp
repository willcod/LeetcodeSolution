/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
      int targetof3 = target - nums[i];
      for (int j = i + 1; j < nums.size(); j++) {
        int targetof2 = targetof3 - nums[j];
        int f = j + 1;
        int b = nums.size() - 1;

        while (f < b) {
          int sumof2 = nums[f] + nums[b];
          if (sumof2 > targetof2)
            b--;
          else if (sumof2 < targetof2)
            f++;
          else {
            vector<int> sub = {nums[i], nums[j], nums[f], nums[b]};
            result.push_back(sub);

            while (f < b && nums[f] == sub[2]) f++;
            while (f < b && nums[b] == sub[3]) b--;
          }
        }

        while (j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
      }
      while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
    }
    return result;
  }
};
// @lc code=end
