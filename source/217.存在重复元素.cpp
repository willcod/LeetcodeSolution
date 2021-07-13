/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;

        for(auto num : nums) {
            count[num]++;
            if (count[num] > 1)
                return true;
        }
        
        return false;
    }
};
// @lc code=end
 
