/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
    struct cmp {
        bool operator() (vector<int>&a, vector<int>&b) {
            return pow(a[0], 2) + pow(a[1], 2) < pow(b[0], 2) + pow(b[1], 2);
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> q;

        for (auto p : points) {
            q.push(p);
            if (q.size() > K) {
                q.pop();
            }
        }

        vector<vector<int>> res;
        while (!q.empty()) {
            res.push_back(q.top());
            q.pop();
        }

        return res;
    }
};
// @lc code=end

