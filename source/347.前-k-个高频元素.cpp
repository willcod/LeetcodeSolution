/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include "cpp_includes.h"
// @lc code=start
struct cmp {
  bool operator()(pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second;
  }
};

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int n : nums) {
      freq[n]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    for (auto kv : freq) {
      pq.push(kv);
      if (pq.size() > k) {
        pq.pop();
      }
    }

    vector<int> res;
    while (!pq.empty()) {
      auto kv = pq.top();
      pq.pop();
      res.push_back(kv.first);
    }

    return res;
  }
};
// @lc code=end
