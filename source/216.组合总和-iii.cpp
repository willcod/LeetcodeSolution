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
        vector<vector<int>> res;
        vector<int> path;

        vector<int> nums;
        for (int i = 1; i <= 9; i++) {
            nums.push_back(i);
        }

        combination(res, path, nums, k, n, 0);
        return res;
    }

    void combination(vector<vector<int>>&res, vector<int>& path, vector<int>& nums, int k, int n, int index) {
        if (n == 0 && path.size() == k) {
            res.push_back(path);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            path.push_back(nums[i]);
            combination(res, path, nums, k, n - nums[i], i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end

