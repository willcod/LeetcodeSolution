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

        stack<int> stk;
        int area = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (stk.size() && heights[stk.top()] >= heights[i]) {
                int cur = stk.top();
                stk.pop();
                if (stk.empty()) {
                    area = max(area, i * heights[cur]);
                } else {
                    int l = stk.top();
                    area = max(area, (i - l - 1) * heights[cur]);
                }
            }
            stk.push(i);
        }

        return area;
    }
};
// @lc code=end
