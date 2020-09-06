/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
class Solution {
 public:
  bool judgeCircle(string moves) {
    int x = 0;
    int y = 0;
    for (auto m : moves) {
      switch (m) {
        case 'R':
          x += 1;
          break;
        case 'L':
          x += -1;
          break;
        case 'U':
          y += 1;
          break;
        case 'D':
          y += -1;
          break;
      }
    }
    return x == 0 && y == 0;
  }
};
// @lc code=end
