/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();

        int maxlen = 1;
        int len = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                len++;
                maxlen = max(maxlen, len);
            } else {
                len = 1;
            }
        }
        return maxlen;
    }
};
// @lc code=end
