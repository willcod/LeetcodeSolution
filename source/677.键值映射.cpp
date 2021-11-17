/*
 * @lc app=leetcode.cn id=677 lang=cpp
 *
 * [677] 键值映射
 */
#include "cpp_includes.h"
// @lc code=start
class MapSum {
 public:
  MapSum() {}

  void insert(string key, int val) { cnt[key] = val; }

  int sum(string prefix) {
    int res = 0;
    for (auto &[key, val] : cnt) {
      if (key.substr(0, prefix.size()) == prefix) {
        res += val;
      }
    }
    return res;
  }

 private:
  unordered_map<string, int> cnt;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end
