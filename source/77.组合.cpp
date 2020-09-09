/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n < k) return {};

        vector<vector<int>> res;
        vector<int> path;
        backtracking(res, path, n, k, 1);
        return res;
    }

    void backtracking(vector<vector<int>>& res, vector<int>& path, int n, int k, int index) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        for (int i = index; i <= n; i++) {
            path.push_back(i);
            backtracking(res, path, n, k, i+1);
            path.pop_back();
        }
    }
};
// @lc code=end

