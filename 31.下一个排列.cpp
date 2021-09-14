/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       auto begin = is_sorted_until(nums.rbegin(), nums.rend());
       if (begin != nums.rend()) {
           auto target = upper_bound(nums.rbegin(), begin, *begin);
           iter_swap(target, begin);
       } 
       reverse(nums.rbegin(), begin);
    }
};
// @lc code=end

