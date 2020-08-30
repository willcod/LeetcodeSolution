/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> results;
    getPermute(results, nums, 0, nums.size() - 1);
    return results;
  }

  void getPermute(vector<vector<int>>& results, vector<int>& nums, int start,
                  int end) {
    if (start == end) {
      results.push_back(nums);
      return;
    }

    for (int i = start; i <= end; i++) {
      swap(nums[i], nums[start]);
      getPermute(results, nums, start + 1, end);
      swap(nums[i], nums[start]);
    }
  }
};
// @lc code=end

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> results;
    vector<bool> used(nums.size(), false);
    vector<int> sub;
    backtracking(results, nums, sub, 0, used);
    return results;
  }

  void backtracking(vector<vector<int>>& results, vector<int>& nums,
                    vector<int>& sub, int pos, vector<bool>& used) {
    if (pos == nums.size()) {
      results.push_back(sub);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (used[i] == false) {
        sub.push_back(nums[i]);
        used[i] = true;
        backtracking(results, nums, sub, pos + 1, used);
        sub.pop_back();
        used[i] = false;
      }
    }
  }
};