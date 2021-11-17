/*
 * @lc app=leetcode.cn id=391 lang=cpp
 *
 * [391] 完美矩形
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  bool isRectangleCover(vector<vector<int>>& rectangles) {
    int sumArea = 0;
    int left = INT_MAX;
    int low = INT_MAX;
    int right = INT_MIN;
    int high = INT_MIN;
    set<string> s;

    for (auto& r : rectangles) {
      left = min(left, r[0]);
      low = min(low, r[1]);
      right = max(right, r[2]);
      high = max(high, r[3]);

      sumArea += (r[2] - r[0]) * (r[3] - r[1]);

      string ll = to_string(r[0]) + " " + to_string(r[1]);
      string lr = to_string(r[2]) + " " + to_string(r[1]);
      string hl = to_string(r[0]) + " " + to_string(r[3]);
      string hr = to_string(r[2]) + " " + to_string(r[3]);

      if (!s.count(ll))
        s.insert(ll);
      else
        s.erase(ll);
      if (!s.count(lr))
        s.insert(lr);
      else
        s.erase(lr);
      if (!s.count(hl))
        s.insert(hl);
      else
        s.erase(hl);
      if (!s.count(hr))
        s.insert(hr);
      else
        s.erase(hr);
    }
    string ll = to_string(left) + " " + to_string(low);
    string lr = to_string(right) + " " + to_string(low);
    string hl = to_string(left) + " " + to_string(high);
    string hr = to_string(right) + " " + to_string(high);

    if (s.size() == 4 && s.count(ll) && s.count(lr) && s.count(hl) &&
        s.count(hr)) {
      return sumArea == (high - low) * (right - left);
    }
    return false;
  }
};
// @lc code=end
