/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 2) return nums.size();

    int j = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[i - 1]) {
        nums[j++] = nums[i];
      }
    }
    return j;
  }
};
// @lc code=end
