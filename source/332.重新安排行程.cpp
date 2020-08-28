/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    for (auto ticket : tickets) {
      Flights[ticket[0]].insert(ticket[1]);
    }

    vector<string> path;
    visit(path, "JFK");

    reverse(path.begin(), path.end());
    return path;
  }

  void visit(vector<string>& path, string airport) {
    while (!Flights[airport].empty()) {
      string next = *Flights[airport].begin();
      Flights[airport].erase(Flights[airport].begin());
      visit(path, next);
    }
    path.push_back(airport);
  }

 private:
  unordered_map<string, multiset<string>> Flights;
};
// @lc code=end
