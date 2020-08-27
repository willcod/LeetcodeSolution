/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> d;
    for (int i = 0; i < nums.size(); i++) {
      while (!d.empty() && nums[i] > nums[d.back()]) d.pop_back();
      d.push_back(i);

      if (i >= k - 1) result.push_back(nums[d.front()]);
      if (d.front() <= i - k + 1) d.pop_front();
    }
    return result;
  }
};
// @lc code=end
