/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && nums[i] > nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);

            if (i >= k - 1) res.push_back(nums[dq.front()]);
            if (dq.front() <= i - k + 1) dq.pop_front();
        }

        return res;
    }
};
// @lc code=end

