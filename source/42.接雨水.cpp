/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 2) return 0;

        stack<int> stk;

        int water = 0;
        for (int i = 0; i < n; i++) {
            while (stk.size() && height[stk.top()] < height[i]) {
                int cur = stk.top();
                stk.pop();
                if (!stk.empty()) {
                    int l = stk.top();
                    int r = i;
                    water += (r - l - 1) * (min(height[l], height[r]) - height[cur]);
                }
            }

            stk.push(i);
        }

        return water;
    }
};
// @lc code=end
