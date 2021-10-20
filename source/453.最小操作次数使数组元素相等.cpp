/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    int minMoves(vector<int>& nums) {
        /* 排序，
        如果最大值和最小值不同，那么最大值减一
        计数+1
        如果相同，break
        */
       int count = 0;
       int min = *min_element(nums.begin(), nums.end());
        for(auto n : nums) {
            count += n - min;
        }

       return count;
    }
};
// @lc code=end

