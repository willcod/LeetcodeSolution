/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1;
        int end = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                start = i;
                end = start;
                while (end + 1 < nums.size() && nums[end + 1] == target) end++;

                return {start, end};
            }
        }

        return {start, end};
    }
};
// @lc code=end
