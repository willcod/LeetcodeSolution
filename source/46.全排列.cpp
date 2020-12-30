/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permute(res, nums, 0);
        return res;
    }

    void permute(vector<vector<int>>& res, vector<int>& nums,
                 int index) {
        if (index == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);
            permute(res, nums, index + 1);
            swap(nums[i], nums[index]);
        }
    }
};
// @lc code=end
