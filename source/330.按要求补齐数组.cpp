/*
 * @lc app=leetcode.cn id=330 lang=cpp
 *
 * [330] 按要求补齐数组
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1, added = 0, i = 0;
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                added++;
            }
        }
        return added;
    }
};
// @lc code=end
