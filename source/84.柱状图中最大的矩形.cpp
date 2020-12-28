/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();

        int res = 0;
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                int pre = stk.top();
                stk.pop();
                if (stk.empty()) {
                    res = max(res, i*heights[pre]);
                } else {
                    int left = stk.top();
                    res = max(res, (i-left-1)*heights[pre]);
                }
            }

            stk.push(i);
        }

        return res;
    }
};
// @lc code=end
