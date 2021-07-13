/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.empty()) return -1;

        sort(nums.begin(), nums.end());

        stack<int> stk;
        stk.push(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            if (!stk.empty() && stk.top() == nums[i]) stk.pop();
            else stk.push(nums[i]);
        }

        return stk.top();
    }
};
// @lc code=end

