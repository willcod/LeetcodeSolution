/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 2) return;

        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                nums[left++] = nums[right];
            }
        }

        for (int i = left; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
// @lc code=end

