/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution {
 public:
  int findComplement(int num) {
      int guard = num;
      int pos = 0;

      while(guard) {
          guard >>= 1;
          num ^= (1 << pos);
          pos++;
      }

      return num;
  }
};
// @lc code=end
