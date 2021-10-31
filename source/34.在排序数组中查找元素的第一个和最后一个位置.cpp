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


        int l = binarySearch(nums, target);
        int r = binarySearch(nums, target+1);

        if (l == r) {
            return {-1, -1};
        } else {
            return {l, r-1};
        }
    }

    int binarySearch(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
};
// @lc code=end

