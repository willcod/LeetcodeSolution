/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;

        stack<int> stk;
        int water = 0;
        int i = 0;
        while (i < height.size()) {
            if (stk.empty() || height[stk.top()] >= height[i]) {
                stk.push(i++);
            } else {
                int pre = stk.top();
                stk.pop();
                if (!stk.empty()) {
                    int minHeight = min(height[stk.top()], height[i]);
                    water += (minHeight - height[pre]) * (i - stk.top() -1);
                }
            }
        }
        return water;
    }
};
// @lc code=end

