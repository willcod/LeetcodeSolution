/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= 3 && i + j < s.length(); j++) {
        for (int k = 1; k <= 3 && i + j + k < s.length(); k++) {
          auto a = s.substr(0, i);
          auto b = s.substr(i, j);
          auto c = s.substr(i + j, k);
          auto d = s.substr(i + j + k);

          if (isValid(a) && isValid(b) && isValid(c) && isValid(d)) {
            result.push_back(a + "." + b + "." + c + "." + d);
          }
        }
      }
    }
    return result;
  }

  bool isValid(string ip) {
    return ip.length() > 0 && ip.length() <= 3 && stoi(ip) <= 255 &&
           (ip[0] != '0' || ip.length() == 1);
  }
};
// @lc code=end
