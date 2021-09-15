/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int dist = 0;

    vector<int> pre = {0, 0};
    set<vector<int>> obs;
    for (auto ob : obstacles) obs.insert(ob);

    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int d = 0;

    for (auto c : commands) {
      if (c == -2) d = (d + 3) % 4;
      if (c == -1) d = (d + 1) % 4;

      for (int i = 0; i < c; i++) {
        vector<int> next = {pre[0] + dir[d][0], pre[1] + dir[d][1]};
        if (obs.count(next)) break;

        pre = next;
        dist = max(dist, next[0] * next[0] + next[1] * next[1]);
      }
    }
    return dist;
  }
};
// @lc code=end
