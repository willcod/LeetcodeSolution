/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int start = 0;
        int end = 0;

        for (int i = 0; i <nums.size()-1; i++) {
            end = max(end, nums[i]+i);
            if (start == i) {
                count++;
                start = end;
            }
        }

        return count;
    }
};
// @lc code=end

