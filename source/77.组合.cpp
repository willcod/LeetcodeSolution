/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        vector<vector<int>> res;
        vector<int> path;
        combine(res, path, nums, k, 0);
        return res;
    }

    void combine(vector<vector<int>>& res, vector<int>& path, vector<int>& nums,
                 int k, int index) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        if (index == nums.size()) return;

        for (int i = index; i < nums.size(); i++) {
            path.push_back(nums[i]);
            combine(res, path, nums, k, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end
