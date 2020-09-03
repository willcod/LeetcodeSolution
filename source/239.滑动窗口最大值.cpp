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
        deque<int> window;

        for (int i = 0; i < nums.size(); i++) {
            while(!window.empty() && nums[window.back()] <= nums[i]) window.pop_back();
            window.push_back(i);

            if (i >= k - 1) result.push_back(nums[window.front()]);
            if (window.front() <= i - k + 1) window.pop_front();
        }
        return result;
    }
};
// @lc code=end

