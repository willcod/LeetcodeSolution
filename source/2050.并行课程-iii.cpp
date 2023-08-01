/*
 * @lc app=leetcode.cn id=2050 lang=cpp
 *
 * [2050] 并行课程 III
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1);
    vector<int> memo(n + 1, 0);
    indegree[0] = -1;

    for (const auto& r : relations) {
      graph[r.front()].push_back(r.back());
      indegree[r.back()]++;
    }

    vector<int> level;
    for (const auto& course : indegree) {
      if (course == 0) {
        level.push_back(&course - &indegree.front());
      }
    }

    int totalMonths = 0;
    for (const auto& l : level) {
      totalMonths = max(totalMonths, dfs(graph, l, time, memo));
    }

    return totalMonths;
  }

  int dfs(vector<vector<int>>& graph, int level, const vector<int>& time,
          vector<int>& memo) {
    if (memo[level] != 0) {
      return memo[level];
    }

    int maxTime = 0;
    for (const auto& next : graph[level]) {
      maxTime = max(maxTime, dfs(graph, next, time, memo));
    }
    return memo[level] = maxTime + time[level - 1];
  }
};
// @lc code=end
https://leetcode.com/problems/parallel-courses-iii/solutions/3667557/simple-dfs-memo/