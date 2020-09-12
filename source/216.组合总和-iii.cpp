/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for (int i = 1; i <= 9; i++) {
            nums.push_back(i);
        }
        vector<vector<int>> res;
        vector<int> p;
        backtracking(res, p, nums, k, n, 0);
        return res;
    }

    void backtracking(vector<vector<int>>& res, vector<int>& p, vector<int>& nums, int k, int n, int index) {
        if (p.size() == k && n == 0) {
            res.push_back(p);
            return;
        }

        for (int i = index; i < nums.size(); i++) {

            p.push_back(nums[i]);
            backtracking(res, p, nums, k, n - nums[i], i + 1);
            p.pop_back();
        }
    }
};
// @lc code=end

