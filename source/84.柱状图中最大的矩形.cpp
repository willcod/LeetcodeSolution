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
        int res = 0;
        heights.push_back(0);

        int n = heights.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int pre = st.top();
                st.pop();
                if (st.empty()) {
                    res = max(res, i * heights[pre]);
                } else {
                    int left = st.top();
                    res = max(res, (i - left - 1) * heights[pre]);
                }
            }
            st.push(i);
        }

        return res;
    }
};
// @lc code=end
