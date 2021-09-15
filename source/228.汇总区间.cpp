/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        if (n == 1) return {to_string(nums[0])};

        vector<string> res;
        for (int i = 0; i < n; i++) {
            int start = nums[i];
            cout << start;
            while (i < n - 1 && nums[i + 1] == nums[i] + 1) i++;

            if (start == nums[i]) {
                res.push_back(to_string(start));
            } else {
                res.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
        }

        return res;
    }
};
// @lc code=end
