/*
 * @lc app=leetcode.cn id=1438 lang=cpp
 *
 * [1438] 绝对差不超过限制的最长连续子数组
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int longestSubarray(vector<int>& nums, int limit) {
        int start = 0;
        int end = 0;
        int maxlen = 0;

        multiset<int> set;
        while (end < nums.size()) {
            set.insert(nums[end]);
            while (*set.rbegin() - *set.begin() > limit) {
                set.erase(set.find(nums[start]));
                start++;
            }
            maxlen = max(maxlen, end - start + 1);
            end++;
        }
        return maxlen;
    }
};
// @lc code=end
