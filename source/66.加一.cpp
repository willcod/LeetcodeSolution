/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int> result;
    int i = digits.size() - 1;

    while (i >= 0) {
      if (digits[i] == 9) {
        digits[i--] = 0;
      } else {
        digits[i]++;
        return digits;
      }
    }

    digits[0] = 1;
    digits.push_back(0);
    return digits;
  }
};
// @lc code=end
