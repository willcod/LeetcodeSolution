/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int end = 0;
        for (int i = 0; i <= end; i++) {
            end = max(end, nums[i] + i);
            if (end >= nums.size() - 1) return true;
        }
        return false;
    }
};
// @lc code=end
