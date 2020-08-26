/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
typedef unordered_map<string, priority_queue<string, vector<string>, greater<string>>> Map;
class Solution {
 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    vector<string> result;
    Map map;
    for (auto t : tickets) {
      map[t[0]].push(t[1]);
    }

    Dfs(result, map, "JFK");
    reverse(result.begin(), result.end());
    return result;
  }

  void Dfs(vector<string>& result, Map& map, string curr) {
    while (map.count(curr) && map[curr].size() > 0) {
      auto next = map[curr].top();
      map[curr].pop();
      Dfs(result, map, next);
    }
    result.push_back(curr);
  }
};
// @lc code=end
