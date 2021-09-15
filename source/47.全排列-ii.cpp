/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> visited(nums.size(), false);
        permute(res, path, visited, nums);
        return res;
    }

    void permute(vector<vector<int>>& res, vector<int>& path,
                 vector<bool>& visited, vector<int>& nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

            if (visited[i] == false) {
                path.push_back(nums[i]);
                visited[i] = true;
                permute(res, path, visited, nums);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
};
// @lc code=end
