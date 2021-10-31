/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  vector<string> findWords(vector<string>& words) {
    vector<string> res;

    for (string str : words) {
      int row = GetRow(str[0]);
      bool same = true;
      for (int i = 1; i < str.length(); i++) {
        if (row != GetRow(str[i])) {
            same = false;
            break;
        }
      }
      if(same) res.push_back(str);
    }
    return res;
  }

  int GetRow(char c) {
    string row1 = "qwertyuiopQWERTYUIOP";
    string row2 = "asdfghjklASDFGHJKL";
    string row3 = "zxcvbnmZXCVBNM";

    if (row1.find(c) != -1)
      return 1;
    else if (row2.find(c) != -1)
      return 2;
    else
      return 3;
  }
};
// @lc code=end
