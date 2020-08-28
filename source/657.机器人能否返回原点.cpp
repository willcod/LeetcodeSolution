/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
class Solution {
 public:
  bool judgeCircle(string moves) {
      int v = 0;
      int h = 0;
      for (char c : moves) {
          switch(c) {
              case 'U' : v++; break;
              case 'D' : v--; break;
              case 'L' : h++; break;
              case 'R' : h--; break;
          }
      }
      return v==0 && h == 0;
  }
};
// @lc code=end
