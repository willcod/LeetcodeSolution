/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string, multiset<string>> flights;
    for (auto t : tickets) {
      flights[t[0]].insert(t[1]);
    }

    vector<string> path;
    visit(path, "JFK", flights);

    reverse(path.begin(), path.end());
    return path;
  }

  void visit(vector<string>& path, string airport,
             unordered_map<string, multiset<string>>& flights) {
    while (!flights[airport].empty()) {
      string next = *flights[airport].begin();
      flights[airport].erase(flights[airport].begin());
      visit(path, next, flights);
    }

    path.push_back(airport);
  }
};
// @lc code=end
