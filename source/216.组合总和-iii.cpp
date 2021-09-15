/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (n < k) return {};

        vector<vector<int>> res;
        vector<int> path;
        vector<int> nums;
        for (int i = 1; i <= 9; i++) {
            nums.push_back(i);
        }
        combinationSum3(res, path, nums, k, n, 0);
        return res;
    }

    void combinationSum3(vector<vector<int>>& res, vector<int>& path,
                         vector<int>& nums, int k, int n, int index) {
        if (path.size() == k && n == 0) {
            res.push_back(path);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            path.push_back(nums[i]);
            combinationSum3(res, path, nums, k, n - nums[i], i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end
