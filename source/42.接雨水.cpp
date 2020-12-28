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
        stack<int> stk;

        int n = height.size();
        int water = 0;
        for (int i = 0; i < n; i++) {
            while (stk.size() && height[stk.top()] < height[i]) {
                int cur = stk.top();
                stk.pop();
                if (!stk.empty()) {
                    int l = stk.top();
                    int r = i;
                    int h = min(height[l], height[r]) - height[cur];
                    water += h * (r - l - 1);
                }
            }

            stk.push(i);
        }
        return water;
    }
};
// @lc code=end
