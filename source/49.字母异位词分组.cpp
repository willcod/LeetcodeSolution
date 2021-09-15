/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, int> hashmap;

    int index = 0;
    for (string s : strs) {
      string t = s;
      sort(t.begin(), t.end());
      if (hashmap.find(t) != hashmap.end()) {
        res[hashmap[t]].push_back(s);
      } else {
        hashmap[t] = index++;
        res.push_back({s});
      }
    }

    return res;
  }
};
// @lc code=end

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> hashmap;

    for (string s : strs) {
      string t = s;
      sort(t.begin(), t.end());
      hashmap[t].push_back(s);
    }

    for (auto kv : hashmap) {
      res.push_back(kv.second);
    }

    return res;
  }
};