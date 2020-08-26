/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
typedef unordered_map<
    string, 
    priority_queue<string, vector<string>, 
    std::greater<string>>> VecHeap;
class Solution {
 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    vector<string> result;

    VecHeap vec;

    for (auto it : tickets) {
      vec[it[0]].push(it[1]);
    }

    dfs(result, vec, "JFK");

    reverse(result.begin(), result.end());
    return result;
  }

 private:
  void dfs(vector<string>& result, VecHeap& vec, string curr) {
    while (vec.count(curr) && vec[curr].size() > 0) {
      string next = vec[curr].top();
      vec[curr].pop();
      dfs(result, vec, next);
    }
    result.push_back(curr);
  }
};
// @lc code=end
