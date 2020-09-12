/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
 public:
  int trap(vector<int>& pillars) {
    if (pillars.size() < 3) return 0;

    int left = 0;
    int right = pillars.size() - 1;

    int leftArea = 0;
    int rightArea = 0;

    int water = 0;
    while (left < right) {
      leftArea = max(leftArea, pillars[left]);
      rightArea = max(rightArea, pillars[right]);

      if (leftArea < rightArea) {
        water += leftArea - pillars[left++];
      } else {
        water += rightArea - pillars[right--];
      }
    }

    return water;
  }
};
// @lc code=end
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