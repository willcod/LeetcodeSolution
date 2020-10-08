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
        int left = 0;
        int right = height.size() - 1;

        int water = 0;
        int leftArea = 0;
        int rightArea = 0;

        while (left < right) {
            leftArea = max(leftArea, height[left]);
            rightArea = max(rightArea, height[right]);

            if (leftArea < rightArea) {
                water += leftArea - height[left++];
            } else {
                water += rightArea - height[right--];
            }
        }

        return water;
    }
};
// @lc code=end
